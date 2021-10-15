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

	EffvsObs.clear();
	EffvsObsNo.clear();
	triggerNames.clear();
	//if(!EffvsObsMet){
		//delete EffvsObsMet;
	//}
	if(!OutputHisto){
		delete OutputHisto;
	}
}





//*************************************************************
//LOAD THE USER'S CONFIG


void TrigEff::LoadNoMap(const vector<string> &triggerNames, const vector<string> &SelectedTriggerNames,int ErrorType, string NameVar,string FileName){ 
	
	
}




//***************************************************************************************************************************

//***************************************************************************************************************************


void TrigEff::FillNoMap2(vector< pair<int, bool > > PosPass, float Obs, double weight,string mode){  //const vector<bool> 
	
}


void TrigEff::ReadFromTxt(const string NameListForType){

	ifstream ifile(NameListForType.c_str()); 
	string tmp;

	while(getline(ifile,tmp)){
   		triggerNames.push_back(tmp);
	}
	cout << triggerNames.size() << endl;
	ifile.close();
}



void TrigEff::StudyRecoMet(bool trig,double Obs){
	
	EffvsObsMet->Fill(trig,Obs);
	
}

void TrigEff::NameTEff(){
	EffvsObs[0]->SetName("Charged+Charged Mu");
	EffvsObs[1]->SetName("Charged+Neutral Mu");
	EffvsObsNo[0]->SetName("Charged+Charged NoMu");
	EffvsObsNo[1]->SetName("Charged+Neutral NoMu");

	
}

void TrigEff::InitTEff(){
	EffvsObs.resize(2); // nb of trigger we study
	EffvsObsNo.resize(2);
	TString outputfilename="TestStop.root";//FileName.c_str();
	OutputHisto = new TFile(outputfilename,"RECREATE");

	EffvsObsMet = new TEfficiency("Eff of PFMET120_PFMHT120", "Efficiency of PFMET120_PFMHT120;Reco pf_MET [GeV];#epsilon",50,0,2000);

	for(int j=0; j < EffvsObs.size(); j++){	
		EffvsObs[j] = new TEfficiency("Eff Mu","Efficiency;Reco pf_MET [GeV];#epsilon",50,0,2000);
		EffvsObsNo[j] = new TEfficiency("Eff NoMu","Efficiency;Reco pf_MET [GeV];#epsilon",50,0,2000);
	}
	NameTEff();
}		

void TrigEff::FindTurnOn(int which,bool trig1, bool trig2, float Obs,bool munomu){
	if(munomu==1){
		EffvsObs[which]->TEfficiency::Fill(trig1,Obs);
	}
	else{
		EffvsObsNo[which]->TEfficiency::Fill(trig2,Obs);
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
	
}



void TrigEff::ComputeErrorLogicalOr(){
	
}







void TrigEff::ComputeError(){
	
}

void TrigEff::WritePlots(string NameVar,string NameOfFile){ //TFile* OutputHisto
	OutputHisto->cd();
	
	for(int i=0;i < EffvsObs.size();i++){
		EffvsObs[i]->Write();
		EffvsObsNo[i]->Write();
	}

	EffvsObsMet->Write();
	OutputHisto->Close();
}

void TrigEff::FillMass(double INVMASS,int choice){
		
}

void TrigEff::Compute(string NameOutputFile,string NameListEff, string ListAllTriggers, string EffTriggers, string ErrorEffTriggers,string EffOrAllTriggers){
	
	//ComputeEff();
	//ComputeError();
	
	//PrintNumEff();
	//PrintDenomEff();
	//PrintEff();
	//ComputeCorAll();
	//SaveIntTrigs(NameOutputFile,NameListEff,ListAllTriggers,EffTriggers, ErrorEffTriggers,EffOrAllTriggers);

	//ComputeCorr();

	//PrintDenomCorr();
	//PrintCorr();
	//ComputeLogicalOr();
	//PrintLogicalOr();
	
}

