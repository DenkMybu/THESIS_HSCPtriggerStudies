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



void TrigEff::NameTEff(){
	EffvsObs[0]->SetName("Charged+Charged");
	EffvsObs[1]->SetName("Charged+Neutral");
}

void TrigEff::InitTEff(){
	EffvsObs.resize(2); // nb of trigger we study
	TString outputfilename="TestStop.root";//FileName.c_str();
	OutputHisto = new TFile(outputfilename,"RECREATE");

	for(int j=0; j < EffvsObs.size(); j++){	
		EffvsObs[j] = new TEfficiency("Eff","Efficiency;Reco pf_MET [GeV];#epsilon",50,0,2000);
	}
	NameTEff();
}		

void TrigEff::FindTurnOn(int which,bool trig1, float Obs){
	EffvsObs[which]->TEfficiency::Fill(trig1,Obs);
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
	}

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

