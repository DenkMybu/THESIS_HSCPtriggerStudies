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

using namespace std;



TrigEff::TrigEff(){
	OutputHisto=0;
}



TrigEff::~TrigEff(){ 
	EffvsObsAll.clear();
	EffvsPom.clear();
	NamesPos.clear();
	TriggerNames.clear();
	

	Efficiency.clear();
	
	NumEfficiency.clear();
	DenomEfficiency.clear();
	
	EffErr.clear();

	if(!OutputHisto){
		delete OutputHisto;
	}
}





//*************************************************************
//LOAD THE USER'S CONFIG


void TrigEff::LoadNoMap(const vector<string> &triggerNames,int ErrorType, string NameVar,string FileName){ 
	
	EffvsObsAll.resize(triggerNames.size());
	NamesPos.resize(triggerNames.size());

	EffvsPom.resize(triggerNames.size());
	
	Efficiency.resize(triggerNames.size(), 0.0);
	
	NumEfficiency.resize(triggerNames.size(), 0.0);
	DenomEfficiency.resize(triggerNames.size(), 0.0);
	
	EffErr.resize(triggerNames.size(), 0.0);
	//Trig.resize(triggerNames.size());

	this->TriggerNames = triggerNames;
	string pom = "POM";
	for(int i =0; i < triggerNames.size(); i++){
		string namepom = ((triggerNames[i].c_str()) + pom).c_str();

		EffvsObsAll[i] = new TEfficiency("Eff","Efficiency;Reco pf_MET [GeV];#epsilon",100,0,2000); 
		EffvsObsAll[i]->SetName(triggerNames[i].c_str());

		EffvsPom[i] = new TEfficiency("Eff","Efficiency;#beta #gamma;#epsilon",100,0,5);
		EffvsPom[i]->SetName(namepom.c_str());

		NamesPos[i] = make_pair(triggerNames[i],i);
	}
	
}




//***************************************************************************************************************************

//***************************************************************************************************************************


void TrigEff::FillNoMap(string TriggerName, bool trig, float Obs, double weight,string mode){  //const vector<bool> 
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
				//cout << "Filling with POM as obs = " << Obs << " and trigger val : " << trig << endl;
				EffvsPom[NamesPos[i].second]->Fill(trig,Obs);
			}
		}
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


void TrigEff::PrintDenomEff(){
	for ( int i = 0; i < DenomEfficiency.size(); i++ ){
      		cout << i << NamesPos[i].first << " -> " << NumEfficiency[i] << " /" << DenomEfficiency[i] << " = " << Efficiency[i]*100.0 << " +/- " << EffErr[i]*100.0 << endl ;
	}
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
	
	for(int j=0; j < EffvsObsAll.size() ; j++){
		EffvsObsAll[j]->Write();
		EffvsPom[j]->Write();
	}
	OutputHisto->Close();
}

void TrigEff::FillMass(double INVMASS,int choice){
		
}

void TrigEff::Compute(string NameOutputFile,string NameListEff, string ListAllTriggers, string EffTriggers, string ErrorEffTriggers,string EffOrAllTriggers){
	
	ComputeEff();
	ComputeError();
	
	//PrintNumEff();
	PrintDenomEff();
	//PrintEff();
	//ComputeCorAll();
	//SaveIntTrigs(NameOutputFile,NameListEff,ListAllTriggers,EffTriggers, ErrorEffTriggers,EffOrAllTriggers);

	//ComputeCorr();

	//PrintDenomCorr();
	//PrintCorr();
	//ComputeLogicalOr();
	//PrintLogicalOr();
	
}

