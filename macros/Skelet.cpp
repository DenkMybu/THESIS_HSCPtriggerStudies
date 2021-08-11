#define skelet_cxx
#include "Skelet.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <array>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <algorithm>


using namespace std;

const double massZ = 91.1876;
const double uncertaintyZ = 0.0021;

const double massMu = 0.1056583745;
const double uncertaintyMu = 0.0000000024;

const double massW = 80.379;
const double uncertaintyW = 0.012;

const float TheorMass = 1800;

void AnaEff::Loop()
{
	
	Long64_t nentries = fChain->GetEntriesFast();
	Long64_t nbytes = 0, nb = 0, nbi = 0;
	Long64_t initializing = LoadTree(0); 
	if (initializing < 0) cout << "Aborted"<< endl;
	nbi = fChain->GetEntry(initializing);   nbytes += nbi;
	cout << "Number of triggers for this file  : " << ntrigger << endl;
	cout << " Number of events for this file : " << nentries << endl;

	
	
	//trigEff_selection_obs.LoadNoMap(triggerNames,triggerNames,1,DataType,NameOfFile);  // call a function from other class .h
	

	cout << "Before loop nentries" << endl;
	for (Long64_t jentry=0; jentry<nentries;jentry++) { //All entries
		Long64_t ientry = LoadTree(jentry);
		if(jentry!=0 && jentry%1000==0) cout << "+1k" << " => " << jentry << " , "<<(jentry*1.0/nentries)*100 << " %" << endl;
		if (ientry < 0) break;
        	nb = fChain->GetEntry(jentry);   nbytes += nb;	
	
		
	}

	cout << "After loop nentries" << endl;
	
	cout << "Program terminated without any logic call out of bound" << endl;

}


int main(){

	AnaEff ana;
	ana.Loop();
	
}
