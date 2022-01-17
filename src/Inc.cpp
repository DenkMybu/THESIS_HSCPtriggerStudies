#include "inc/Inc.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TPad.h>
#include <stdio.h>
#include <array>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <TPad.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>
#include <TEntryList.h>
#include <TFrame.h>
#include <TEfficiency.h>

using namespace std;



TrigEff::TrigEff(){
	OutputHisto=0;
	
}



TrigEff::~TrigEff(){ 
	EffvsObsAll.clear();
	EffvsRecoCalo.clear();
	EffvsPom.clear();
	EffvsPt.clear();
	NamesPos.clear();
	TriggerNames.clear();
	

	Efficiency.clear();
	
	NumEfficiency.clear();
	DenomEfficiency.clear();
	
	EffErr.clear();

	if(!OutputHisto){
		delete OutputHisto;
	}
	/*if(!EffVsRecoCal){
		delete EffVsRecoCal;
	}*/
}





//*************************************************************
//LOAD THE USER'S CONFIG


void TrigEff::LoadNoMap(const vector<string> &triggerNames,int ErrorType, string NameVar,string FileName){ 
	
	EffvsObsAll.resize(triggerNames.size());
	NamesPos.resize(triggerNames.size());
	EffvsRecoCalo.resize(triggerNames.size());
	EffvsPom.resize(triggerNames.size());
	EffvsPt.resize(triggerNames.size());
	Efficiency.resize(triggerNames.size(), 0.0);
	
	NumEfficiency.resize(triggerNames.size(), 0.0);
	DenomEfficiency.resize(triggerNames.size(), 0.0);
	
	EffErr.resize(triggerNames.size(), 0.0);
	//Trig.resize(triggerNames.size());

	this->TriggerNames = triggerNames;
	string pom = "POM",pt = "PT",recocalo = "reco::calo";
	
	TEfficiency* EffVsRecoCal = new TEfficiency("Eff","Efficiency hlt_pfmet>90;Reco calo_MET [GeV];#epsilon",100,0,2000);
	EffvsRecoCal->SetName(recocalo.c_str());

	for(int i =0; i < triggerNames.size(); i++){
		string namepom = ((triggerNames[i].c_str()) + pom).c_str();
		string namept = ((triggerNames[i].c_str()) + pt).c_str();
		string namerecocalo = ((triggerNames[i].c_str()) + recocalo).c_str();
		EffvsObsAll[i] = new TEfficiency("Eff","Efficiency;Reco pf_MET [GeV];#epsilon",100,0,2000); 
		EffvsObsAll[i]->SetName(triggerNames[i].c_str());


		EffvsRecoCalo[i] = new TEfficiency("Eff","Efficiency;Reco calo_MET [GeV];#epsilon",100,0,2000);
		EffvsRecoCalo[i]->SetName("TEff_recocalo");
		
		
		EffvsPom[i] = new TEfficiency("Eff","Efficiency;#beta #gamma;#epsilon",100,0,5);
		EffvsPom[i]->SetName(namepom.c_str());

		EffvsPt[i] = new TEfficiency("Eff","Efficiency;PT;#epsilon",100,0,4000);
		EffvsPt[i]->SetName(namept.c_str());
		
		NamesPos[i] = make_pair(triggerNames[i],i);
	}
	
}




//***************************************************************************************************************************

//***************************************************************************************************************************


void TrigEff::FillNoMap(const string &TriggerName, bool trig,const float &Obs,const double &weight,string mode){  //const vector<bool> 
	//cout << "NamesPos.size() = " << NamesPos.size() << endl;
	if(mode == "MET"){	
		for(int i = 0; i < NamesPos.size(); i++){
			if(NamesPos[i].first == TriggerName){
				EffvsObsAll[NamesPos[i].second]->Fill(trig,Obs);
			}
		}
	}
	
	if(mode == "POM"){
		for(int i = 0; i < NamesPos.size(); i++){
			if(NamesPos[i].first == TriggerName){
				//cout << "Filling with POM = " << Obs << " and trigger val : " << trig << endl;
				EffvsPom[NamesPos[i].second]->Fill(trig,Obs);
			}
		}
	}
	if(mode == "PT"){
		for(int i = 0; i < NamesPos.size(); i++){
			if(NamesPos[i].first == TriggerName){
				//cout << "Filling with PT  = " << Obs << " and trigger val : " << trig << endl;
				EffvsPt[NamesPos[i].second]->Fill(trig,Obs);
			}
		}
	}
	if(mode == "CALOMET"){
		for(int i = 0; i < NamesPos.size(); i++){
			if(NamesPos[i].first == TriggerName){
				//cout << "Filling with PT  = " << Obs << " and trigger val : " << trig << endl;
				EffvsRecoCalo[NamesPos[i].second]->Fill(trig,Obs);
			}
		}
		EffvsRecoCal->Fill(trig,Obs);
	}
	
}


void TrigEff::StudyRecoMet(bool trig,double Obs){
		
}

void TrigEff::NameTEff(){

}

void TrigEff::InitTEff(string teffFilename){
	OutputHisto = new TFile(teffFilename.c_str(),"RECREATE");
}		


void TrigEff::FillTrigEff(vector< pair<string, bool > > Trig){

	for(int j=0; j<Trig.size(); j++){
		DenomEfficiency[j] +=1;
		if(Trig[j].second == 1){
			NumEfficiency[j]+=1;
		}	
	}
}


//***************************************************************************************************************************
void TrigEff::StudyTrigvsMass(double mass){

}

void TrigEff::ComputeCorr(){
	
	
}


void TrigEff::ComputeLogicalOr(){
	
}



void TrigEff::PrintLogicalOr(){
	
}



void TrigEff::PrintCorr(){
	
}

void TrigEff::PrintNumCorr(){
	
}

void TrigEff::PrintDenomCorr(){

}

void TrigEff::ComputeEff(){
	
	for(int i=0;i< Efficiency.size();i++){
		if(DenomEfficiency[i]==0 && NumEfficiency[i] == 0){
			Efficiency[i]=0;
		}
		else if(DenomEfficiency[i]==0){
			Efficiency[i]=0;
		}
		else{	
			Efficiency[i] = ((NumEfficiency[i]*1.0) / DenomEfficiency[i]*1.0);
		}
		
	}	
}




void TrigEff::ComputeCorAll(){
	
}


void TrigEff::PrintEff(){

	
}


void TrigEff::SaveIntTrigs(string NameOutputFile, string NameListEff, string ListAllTriggers, string EffTriggers, string ErrorEffTriggers, string EffOrAllTriggers){ // triggersofinterest = EffGluino16001105all.txt
	
	
}

void TrigEff::PrintNumEff(){
		
}


void TrigEff::PrintDenomEff(string Effscenarios){

	EffScenario.open (Effscenarios);
	for ( int i = 0; i < DenomEfficiency.size(); i++ ){
      		cout << i << NamesPos[i].first << " -> " << NumEfficiency[i] << " /" << DenomEfficiency[i] << " = " << Efficiency[i]*100.0 << " +/- " << EffErr[i]*100.0 << endl;
		EffScenario << i << NamesPos[i].first << " -> " << NumEfficiency[i] << " /" << DenomEfficiency[i] << " = " << Efficiency[i]*100.0 << " +/- " << EffErr[i]*100.0 << endl;
	}
	EffScenario.close();
}



void TrigEff::ComputeErrorLogicalOr(){
	
}


void TrigEff::ComputeError(){

	for(int i=0;i< EffErr.size();i++){
		if(Efficiency[i]==0){
			EffErr[i]=0;
		}
		else{
			EffErr[i]=sqrt((Efficiency[i]*(1.0-Efficiency[i]))/DenomEfficiency[i]);
		}
	}
}

void TrigEff::WritePlots(string NameVar,string NameOfFile){ //TFile* OutputHisto
	
	OutputHisto->cd();
	EffvsRecoCal->Write();
	for(int j=0; j < EffvsObsAll.size() ; j++){
		EffvsObsAll[j]->Write();
		EffvsRecoCalo[j]->Write();
		EffvsPom[j]->Write();
		EffvsPt[j]->Write();
	}
	OutputHisto->Close();
}

void TrigEff::FillMass(double INVMASS,int choice){
		
}

void TrigEff::Compute(string Effscenarios,string NameOutputFile,string NameListEff, string ListAllTriggers, string EffTriggers, string ErrorEffTriggers,string EffOrAllTriggers){
	
	ComputeEff();
	ComputeError();
	
	//PrintNumEff();
	PrintDenomEff(Effscenarios);
	//PrintEff();
	//ComputeCorAll();
	//SaveIntTrigs(NameOutputFile,NameListEff,ListAllTriggers,EffTriggers, ErrorEffTriggers,EffOrAllTriggers);

	//ComputeCorr();

	//PrintDenomCorr();
	//PrintCorr();
	//ComputeLogicalOr();
	//PrintLogicalOr();
	
}

