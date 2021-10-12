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
	
}



TrigEff::~TrigEff(){ 

	EffvsObs.clear();
	
}





//*************************************************************
//LOAD THE USER'S CONFIG


void TrigEff::LoadNoMap(const vector<string> &triggerNames, const vector<string> &SelectedTriggerNames,int ErrorType, string NameVar,string FileName){ 
	
	EffvsObs.resize(2); // nb of trigger we study
	
}




//***************************************************************************************************************************

//***************************************************************************************************************************


void TrigEff::FillNoMap2(vector< pair<int, bool > > PosPass, float Obs, double weight,string mode){  //const vector<bool> 
	
}

void TrigEff::FindTurnOn(bool trig1, float Obs){

	for(int j = 0; j < EffvsObs.size() ; j++){
		EffvsObs[i]->TEfficiency::Fill(trig1,Obs);
		
	}
	EffvsObs[0]->SetName("Charged+Charged");
	EffvsObs[1]->SetName("Charged+Neutral");
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

