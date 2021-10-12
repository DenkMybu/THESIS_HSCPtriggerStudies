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

const double TheorMass = 2400;

 
void AnaEff::Loop()
{
	
	Long64_t nentries = fChain->GetEntriesFast();
	Long64_t nbytes = 0, nb = 0, nbi = 0;
	Long64_t initializing = LoadTree(0);
	if (initializing < 0) cout << "Aborted"<< endl;
	nbi = fChain->GetEntry(initializing);   nbytes += nbi;
	cout << "Number of triggers for this file  : " << ntrigger << " , number of events : " << nentries << endl;

	string NameList = "CompleteList", PrescaledList = "PrescaledList", ListAll = "ListOfAllTriggersEff", SubNum = "all", ExtRoot = ".root", ExtTxt = ".txt", Date="05_10_2021", Or = "LogicalOr", TransferTxt="AllInfos", TransferEff = "Eff", TransferZ = "EntriesFromZ", TransferW = "EntriesFromW", ErrorEffTransfer = "Error", TransferDistribZ = "DistribZpeak", TransferDistribW = "DistribWpeak", Data = "Stop", DataType = Data + to_string(int(TheorMass));
	
	string NameCompleteListTest = "ListeInteretTriggers";

	string StudyTxt = TransferTxt + DataType + Date;
	string NameOfTxt = StudyTxt + SubNum + ExtTxt;

	string StudyDistribZ = TransferDistribZ + DataType + Date;


	string distribvarZ = StudyDistribZ + SubNum + ExtRoot;


	//************************************** DECLARATION OF THXD *******************************************************
	//******************************************************************************************************************

	DISTRIB_NB_RHADRONS = new TH1D ("DISTRIB_NB_RHADRONS" , " ( nb r hadrons (all scenarios) )", 16,1,3);
	DISTRIB_NB_RHADRONS->GetXaxis()->SetTitle("# R-hadrons");
	DISTRIB_NB_RHADRONS->GetYaxis()->SetTitle("# events");

	DISTRIB_IAS = new TH1D("DISTRIB_IAS", "( IAS )",80,0,1.2);
	DISTRIB_IAS->GetXaxis()->SetTitle("Ias");
	DISTRIB_IAS->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_IASCHN = new TH1D("DISTRIB_IASCHN", "( IAS ) CHN",80,0,1.2);
	DISTRIB_IASCHN->GetXaxis()->SetTitle("Ias");
	DISTRIB_IASCHN->GetYaxis()->SetTitle("# HSCP");
	
	DISTRIB_IASCHCH = new TH1D("DISTRIB_IASCHCH", "( IAS )CHCH",80,0,1.2);
	DISTRIB_IASCHCH->GetXaxis()->SetTitle("Ias");
	DISTRIB_IASCHCH->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_IASDCH = new TH1D("DISTRIB_IASDCH", "( IAS )DCH",80,0,1.2);
	DISTRIB_IASDCH->GetXaxis()->SetTitle("Ias");
	DISTRIB_IASDCH->GetYaxis()->SetTitle("# HSCP");


	DISTRIB_IH = new TH1D ("DISTRIB_IH", " IH ", 100, 0 , 15);
	DISTRIB_IH->GetXaxis()->SetTitle("Ih");
	DISTRIB_IH->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_IHCHN = new TH1D ("DISTRIB_IHCHN", " IH CHN ", 100, 0 , 15);
	DISTRIB_IHCHN->GetXaxis()->SetTitle("Ih");
	DISTRIB_IHCHN->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_IHCHCH = new TH1D ("DISTRIB_IHCHCH", " IH CHCH", 100, 0 , 30);
	DISTRIB_IHCHCH->GetXaxis()->SetTitle("Ih");
	DISTRIB_IHCHCH->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_IHDCH = new TH1D ("DISTRIB_IHDCH", " IH DCH", 100, 0 , 30);
	DISTRIB_IHDCH->GetXaxis()->SetTitle("Ih");
	DISTRIB_IHDCH->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_METNOSEL = new TH1D("DISTRIB_METNOSEL", "( MET )", 100,0,4000);
	DISTRIB_METNOSEL->GetXaxis()->SetTitle("MET [GeV]");
	DISTRIB_METNOSEL->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_METPRESEL = new TH1D("DISTRIB_METPRESEL", "( MET )", 100,0,4000);
	DISTRIB_METPRESEL->GetXaxis()->SetTitle("MET [GeV]");
	DISTRIB_METPRESEL->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_METSEL = new TH1D("DISTRIB_METSEL", "( MET )", 100,0,4000);
	DISTRIB_METSEL->GetXaxis()->SetTitle("MET [GeV]");
	DISTRIB_METSEL->GetYaxis()->SetTitle("# HSCP");



	DISTRIB_ETA_DCH = new TH1D("DISTRIB_ETA_DCH", "( ETA dch )", 100, -3, 3);
	DISTRIB_ETA_DCH->GetXaxis()->SetTitle(" #Eta ");
	DISTRIB_ETA_DCH->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_MET_CHN = new TH1D ("DISTRIB_MET_CHN", " ( MET CHN) " , 100,0,4000);
	DISTRIB_MET_CHN->GetXaxis()->SetTitle("MET (GeV)");
	DISTRIB_MET_CHN->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_MET_NN = new TH1D ("DISTRIB_MET_NN", " ( MET NN) " , 100,0,4000);
	DISTRIB_MET_NN->GetXaxis()->SetTitle("MET (GeV)");
	DISTRIB_MET_NN->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_MET_CHCH = new TH1D ("DISTRIB_MET_CHCH", " ( MET CHCH) " , 100,0,4000);
	DISTRIB_MET_CHCH->GetXaxis()->SetTitle("MET (GeV)");
	DISTRIB_MET_CHCH->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_P1MP2CHCH = new TH1D ("DISTRIB_P1MP2CHCH", "P1MP2CHCH", 100, -5, 5);
	DISTRIB_P1MP2CHCH->GetXaxis()->SetTitle("2*(p1 - p2) / (p1 + p2)");
	DISTRIB_P1MP2CHCH->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_P1MP2CHN = new TH1D ("DISTRIB_P1MP2CHN", "P1MP2CHN", 100, -5, 5);
	DISTRIB_P1MP2CHN->GetXaxis()->SetTitle("2*(p1 - p2) / (p1 + p2)");
	DISTRIB_P1MP2CHN->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_MET_pt_CHN = new TH2D("DISTRIB_MET_pt_CHN", "Met vs pt chn", 600, 0, 4000, 600, 0, 4000);
	DISTRIB_MET_pt_CHN->GetXaxis()->SetTitle("Reco MET [GeV]");
	DISTRIB_MET_pt_CHN->GetYaxis()->SetTitle("Pt [GeV]");

	DISTRIB_MET_pt_CHCH = new TH2D("DISTRIB_MET_pt_CHCH", "Met vs pt chch", 600, 0, 4000, 600, 0, 4000);
	DISTRIB_MET_pt_CHCH->GetXaxis()->SetTitle("Reco MET [GeV]");
	DISTRIB_MET_pt_CHCH->GetYaxis()->SetTitle("Pt [GeV]");

	DISTRIB_PT1_PT2 = new TH2D("DISTRIB_PT1_PT2", "PT1_PT2 ", 300 , 0 , 2000 , 300, 0 , 2000 );
	DISTRIB_PT1_PT2->GetXaxis()->SetTitle("PT candidate 1");
	DISTRIB_PT1_PT2->GetYaxis()->SetTitle("PT candidate 2");

	DISTRIB_PT1_PT2_CHCH = new TH2D("DISTRIB_PT1_PT2_CHCH", "PT1_PT2_CHCH", 300 , 0 , 2000 , 300, 0 , 2000 );
	DISTRIB_PT1_PT2_CHCH->GetXaxis()->SetTitle("PT charged candidate 1");
	DISTRIB_PT1_PT2_CHCH->GetYaxis()->SetTitle("PT charged candidate 2");

	DISTRIB_PT1_PT2_CHN = new TH2D("DISTRIB_PT1_PT2_CHN", "PT1_PT2_CHN", 300 , 0 , 2000 , 300, 0 , 2000 );
	DISTRIB_PT1_PT2_CHN->GetXaxis()->SetTitle("PT charged candidate");
	DISTRIB_PT1_PT2_CHN->GetYaxis()->SetTitle("PT neutral candidate");

	DISTRIB_PT1_PT2_NN = new TH2D("DISTRIB_PT1_PT2_NN", "PT1_PT2_NN", 300 , 0 , 2000 , 300, 0 , 2000 );
	DISTRIB_PT1_PT2_NN->GetXaxis()->SetTitle("PT neutral candidate 1");
	DISTRIB_PT1_PT2_NN->GetYaxis()->SetTitle("PT neutral candidate 2");

	DISTRIB_P1_P2_CHN = new TH2D("DISTRIB_P1_P2_CHN", "P1_P2CHN", 600 , 0 , 4000 , 600, 0 , 4000 );
	DISTRIB_P1_P2_CHN->GetXaxis()->SetTitle("P charged candidate");
	DISTRIB_P1_P2_CHN->GetYaxis()->SetTitle("P neutral candidate");

	DISTRIB_P1_P2_CHCH = new TH2D("DISTRIB_P1_P2_CHCH", "P1_P2CHCH", 600 , 0 , 4000 , 600, 0 , 4000 );
	DISTRIB_P1_P2_CHCH->GetXaxis()->SetTitle("P charged candidate 1");
	DISTRIB_P1_P2_CHCH->GetYaxis()->SetTitle("P charged candidate 2");


	//******************************************************************************************************************
	//******************************************************************************************************************

	DISTRIB_NB_RHADRONS->Sumw2();

	DISTRIB_IAS->Sumw2();

	DISTRIB_IASCHN->Sumw2();
	DISTRIB_IASCHCH->Sumw2();
	DISTRIB_IASDCH->Sumw2();

	DISTRIB_IH->Sumw2();

	DISTRIB_IHCHN->Sumw2();
	DISTRIB_IHCHCH->Sumw2();
	DISTRIB_IHDCH->Sumw2();
	
	DISTRIB_METNOSEL->Sumw2();
	DISTRIB_METPRESEL->Sumw2();
	DISTRIB_METSEL->Sumw2();

	DISTRIB_P1_P2_CHN->Sumw2();
	DISTRIB_P1_P2_CHCH->Sumw2();

	DISTRIB_ETA_DCH->Sumw2();

	DISTRIB_MET_CHN->Sumw2();
	DISTRIB_MET_NN->Sumw2();
	DISTRIB_MET_CHCH->Sumw2();
	DISTRIB_MET_pt_CHN->Sumw2();
	DISTRIB_MET_pt_CHCH->Sumw2();
	DISTRIB_P1MP2CHCH->Sumw2();
	DISTRIB_P1MP2CHN->Sumw2();

	DISTRIB_PT1_PT2->Sumw2();
	DISTRIB_PT1_PT2_CHCH->Sumw2();
	DISTRIB_PT1_PT2_CHN->Sumw2();
	DISTRIB_PT1_PT2_NN->Sumw2();
	//trigEff_presel.LoadNoMap(triggerNames,triggerNames,1,DataType,NameOfFile);
	
	//trigEff_selection_obs.LoadNoMap(triggerNames,triggerNames,1,DataType,NameOfFile);  // call a function from other class .h
	
	int counter=0,passedevent=0,passedpresel=0,passedsel=0,nbofpairs=0,nbmuons=0,nbwrong=0,indexcandidate, indexcandidatenosel, indexcandidatesel;

	string trigger1="",trigger2="";


	cout << "Working on " << DataType << endl;
	for (Long64_t jentry=0; jentry<nentries;jentry++) { //All entries
		Long64_t ientry = LoadTree(jentry);
		if(jentry!=0 && jentry%1000==0) cout << "+1k" << " => " << jentry << " , "<<(jentry*1.0/nentries)*100 << " %" << endl;
		if (ientry < 0) break;
        	nb = fChain->GetEntry(jentry);   nbytes += nb;	
		counter+=1;
		DISTRIB_METNOSEL->Fill(pfmet_pt[0]);
		indexcandidate=Preselection();
		if(indexcandidate!=64){
			DISTRIB_METPRESEL->Fill(pfmet_pt[0]);
			passedpresel+=1;
			indexcandidatesel = Selection(indexcandidate);
			if(indexcandidatesel != 64){
				DISTRIB_METSEL->Fill(pfmet_pt[0]);
				passedevent+=1;
				DISTRIB_IAS->Fill(track_ias_ampl[hscp_track_idx[indexcandidatesel]]);
				
				//Find trigger bool
				AssoGenId(indexcandidatesel,trig1);
			}
		}

	}

	ofstream InfosData;
	InfosData.open (NameOfTxt);

	
	cout << "--------------------- RHADRONS ---------------- "  << endl;
	cout << " There was " << nbtot << " events, " << nbchn << " charged + neutral and" << nbchch << " charged + charged" << endl;
	cout << " Charged-Charged : " << nbchch << " / " << nbtot << " = " << nbchch*1.0/nbtot <<  endl;
	cout << " Neutral-Charged : " << nbchn << " / " << nbtot << " = "  <<  nbchn*1.0/nbtot << endl;
	cout << " Neutral-X : " << nbnn << " / " << nbtot << " = "  <<  nbnn*1.0/nbtot << endl;
	cout << "Double charged R-hadrons :  " << nbtch << " / " << nbtot << " = " << nbtch*1.0/nbtot << endl;

	//*********************************TXT OUTPUT***********************************
	//******************************************************************************
	
	InfosData << "# events : " << nentries << " , # passing preselection : " << passedpresel << "# selection IAS > 0.2" << passedevent << ", should equal nbtot = " << nbtot << " ¦¦ nb missmatched : " << nbmissmatch << endl;
	InfosData << "*******************************SCENARIOS*******************************" << "\n\n" << endl;
	InfosData << " # Charged-Charged : " << nbchch << " / " << nbtot << " = " << nbchch*1.0/nbtot << endl;
	InfosData << " # Charged-Neutral : " << nbchn << " / " << nbtot << " = " << nbchn*1.0/nbtot << endl;
	InfosData << " # Neutral-Neutral : " << nbnn << " / " << nbtot << " = " << nbnn*1.0/nbtot << endl;
	InfosData << " # Neutral-X : " << nbnx << " / " << nbtot << " = " << nbnx*1.0/nbtot << endl;
	InfosData << " # Double charged - X " << nbtch << " / " << nbtot << " = " << nbtch*1.0/nbtot << endl;

	//******************************************************************************
	//******************************************************************************


	InfosData.close();

	distrib = new TFile(distribvarZ.c_str(),"RECREATE");
	
	distrib->cd();

	//********************************WRITING THXD**********************************
	//******************************************************************************
	DISTRIB_NB_RHADRONS->Write();

	DISTRIB_IAS->Write();

	DISTRIB_IASCHN->Write();
	DISTRIB_IASCHCH->Write();
	DISTRIB_IASDCH->Write();

	DISTRIB_IH->Write();

	DISTRIB_IHCHN->Write();
	DISTRIB_IHCHCH->Write();
	DISTRIB_IHDCH->Write();

	DISTRIB_METNOSEL->Write();
	DISTRIB_METPRESEL->Write();
	DISTRIB_METSEL->Write();

	DISTRIB_P1_P2_CHN->Write();
	DISTRIB_P1_P2_CHCH->Write();
	
	DISTRIB_ETA_DCH->Write();
	DISTRIB_MET_CHN->Write();
	DISTRIB_MET_CHCH->Write();
	DISTRIB_MET_NN->Write();
	DISTRIB_MET_pt_CHN->Write();
	DISTRIB_MET_pt_CHCH->Write();
	DISTRIB_P1MP2CHCH->Write();
	DISTRIB_P1MP2CHN->Write();
	DISTRIB_PT1_PT2->Write();
	DISTRIB_PT1_PT2_CHCH->Write();
	DISTRIB_PT1_PT2_CHN->Write();
	DISTRIB_PT1_PT2_NN->Write();
	//******************************************************************************
	//******************************************************************************

	distrib->Close();
	cout << "Program terminated without any logic call out of bound" << endl;

}
//*********************************PRESELECTION*********************************
//******************************************************************************

int AnaEff::Preselection(){
	int index=64,count2=0;
	vector<int> positions;
	vector< pair<float, int > > Muonpt,HSCPpt,HSCPponm;
	
	bool yon=true;
	for(int ihs=0; ihs<nhscp;ihs++){
		yon=true;
		if( track_eta[hscp_track_idx[ihs]] >= 2.1 || track_eta[hscp_track_idx[ihs]] <= -2.1 ){
			yon=false;
		}
		if( track_npixhits[hscp_track_idx[ihs]] <= 1 ){ //?
			yon=false;
		}
		if( track_nhits[hscp_track_idx[ihs]] <= 4 ){ //7
			yon=false;
		}
		if( track_validfraction[hscp_track_idx[ihs]] <= 0.8 ){
			yon=false;
		}
		if( ndedxhits <= 5 ){
			yon=false;
		}
		if( track_pt[hscp_track_idx[ihs]] <= 55 ){ //55
			yon=false;
		}
		if( track_dxy[hscp_track_idx[ihs]] >=0.5 ){
			yon=false;
		}
		if( track_dz[hscp_track_idx[ihs]] >=0.5 ){
			yon=false;
		}
		if( track_pterr[hscp_track_idx[ihs]]/track_pt[hscp_track_idx[ihs]] >= 1 ){ 
			yon=false;
		}
		if( track_qual[hscp_track_idx[ihs]] < 2 ){//?
			yon=false;
		}
		/*if(track_ias_ampl[hscp_track_idx[ihs]] < 0.8){ 
			yon = false;
		}*/
		
		if(yon){
			positions.push_back(ihs); 
			HSCPpt.push_back(make_pair(track_pt[hscp_track_idx[ihs]],ihs));
			Muonpt.push_back(make_pair(muon_pt[ihs],ihs));
		}
		
	}

	if(positions.size() != 0){
		int siz=Muonpt.size(),sizH = HSCPpt.size();

		sort(Muonpt.begin(),Muonpt.end());
		sort(HSCPpt.begin(),HSCPpt.end());
		return HSCPpt[sizH-1].second;
	}
	else{
		return 64;
	}

}
//******************************************************************************
//******************************************************************************


//***********************************SELECTION***********************************
//*******************************************************************************


int AnaEff::Selection(int indexcandidate){
	if(track_ias_ampl[hscp_track_idx[indexcandidate]] > 0.2){ 
		return indexcandidate;
	}
	else{
		return 64;
	}
	
}
//*******************************************************************************
//*******************************************************************************


void AnaEff::AssoGenId(int indexcandidate,bool trig1){

	vector<int> indexpdgch{1009213, 1009323, 1092214, 1091114, 1093114, 1093224, 1093314, 1093334, 1000612, 1000632, 1000652, 1006211, 1006213, 1006313, 1006321, 1006323 }, indexpdgn{1000622, 1093324, 1092114, 1000993, 1009113, 1009223, 1009313, 1009333, 1093214, 1000642, 1006113, 1006311, 1006313}, indexpdgch2{1006223, 1092224};
	vector<int> candidatesrh,candidatesneutral,candidatesdoublech;
	int nbmothgen=0;

	for(int i=0; i < ngenpart ; i++){
		
		//cout << "Nb of part_gen" << ngenpart << " , gen : " << gen_pdg[i] << " , gen_moth : " << gen_moth_pdg[i] << " , status : " << gen_status[i] << " , p = pt * cosh(eta) : " << gen_pt[i] * cosh(gen_eta[i]) << endl;


		if(gen_moth_pdg[i] == 1000021){
			nbmothgen+=1;
		}
		//******************************** CHARGED RHADRONS********************************
		//*********************************************************************************
		for(int k = 0; k < indexpdgch.size() ; k++){
			if(abs(gen_pdg[i]) == indexpdgch[k]){
				if(gen_status[i] == 1){
					nbch+=1;
					candidatesrh.push_back(i);
				}
			}
		}
		//*********************************************************************************
		//*********************************************************************************



		//******************************** NEUTRAL RHADRONS********************************
		//*********************************************************************************
		for(int j=0; j < indexpdgn.size(); j++){
			if(abs(gen_pdg[i]) == indexpdgn[j]){
				if(gen_status[i] == 1){
				 nbn+=1;
				 candidatesneutral.push_back(i);
				}
			}
		}
		//*********************************************************************************
		//*********************************************************************************
		

		for(int j=0; j < indexpdgch2.size(); j++){
			if(abs(gen_pdg[i]) == indexpdgch2[j]){
				if(gen_status[i] == 1){
					nbdch+=1;
					candidatesdoublech.push_back(i);
					cout << "double charge gen : " << gen_pdg[i] << " , gen_moth : " << gen_moth_pdg[i] << " , status : " << gen_status[i] << " , p = pt * cosh(eta) : " << gen_pt[i] * cosh(gen_eta[i]) << endl;
				}
			}
		}
		
		if ((candidatesrh.size() + candidatesneutral.size() + candidatesdoublech.size()) != 2 ){
			//cout << " There weren't two different rhadrons from all the scenarios possible (mis-matching may be the cause) " << endl;
			nbmissmatch +=1;
		}
	}
	DISTRIB_NB_RHADRONS->Fill(candidatesrh.size() + candidatesneutral.size() + candidatesdoublech.size());
	bool alo = false,alo2=false;
	nbtot+=1;
	if(candidatesdoublech.size() >= 1 ){
		nbtch+=1;
		double eta_track = track_eta[hscp_track_idx[indexcandidate]],phi_track = track_phi[hscp_track_idx[indexcandidate]],eta_gen = gen_eta[candidatesdoublech[candidatesdoublech.size()-1]], phi_gen = gen_phi[candidatesdoublech[candidatesdoublech.size()-1]];
		double deltatranfrdch = deltaR2(eta_track, phi_track, eta_gen, phi_gen);
		double finaldeltadch = deltaR(deltatranfrdch);	

		if(finaldeltadch < 0.3 ){
			DISTRIB_IHDCH->Fill(track_ih_ampl[hscp_track_idx[indexcandidate]]);
			DISTRIB_IASDCH->Fill(track_ias_ampl[hscp_track_idx[indexcandidate]]);
			DISTRIB_ETA_DCH->Fill(track_eta[hscp_track_idx[indexcandidate]]);
		}
	}
	//*******************************NEUTRAL + NEUTRAL*******************************
	//*******************************************************************************


	if(candidatesrh.size() == 0 && candidatesneutral.size() == 2){
		DISTRIB_MET_NN->Fill(pfmet_pt[0]);
		nbnn+=1;
		DISTRIB_PT1_PT2_NN->Fill(gen_pt[candidatesneutral[candidatesneutral.size()-1]],gen_pt[candidatesneutral[candidatesneutral.size()-2]]);
	}

	//*******************************NEUTRAL + XXXXXXX*******************************
	//*******************************************************************************

	if( candidatesrh.size() == 0 && candidatesneutral.size() == 1 ){
		nbnx+=1;
	}


	//*******************************CHARGED + NEUTRAL*******************************
	//*******************************************************************************

	if( candidatesrh.size() == 1 && candidatesneutral.size() == 1 ){
		nbchn+=1;
		//cout << " charged + neutral " << endl;
		double p1 = gen_pt[candidatesrh[candidatesrh.size()-1]] * cosh(gen_eta[candidatesrh[candidatesrh.size()-1]]);
		double p2 = gen_pt[candidatesneutral[candidatesneutral.size()-1]] * cosh(gen_eta[candidatesneutral[candidatesneutral.size()-1]]);
		DISTRIB_MET_CHN->Fill(pfmet_pt[0]);
		
		//cout << " p1 = " << p1 << " , p2 = " << p2 << endl;
		double deltatranfr1chn = deltaR2(track_eta[hscp_track_idx[indexcandidate]], track_phi[hscp_track_idx[indexcandidate]], gen_eta[candidatesrh[candidatesrh.size()-1]], gen_phi[candidatesrh[candidatesrh.size()-1]]);
		double finaldeltachn1 = deltaR(deltatranfr1chn);

		double deltatranfr2chn = deltaR2(track_eta[hscp_track_idx[indexcandidate]], track_phi[hscp_track_idx[indexcandidate]], gen_eta[candidatesneutral[candidatesneutral.size()-1]], gen_phi[candidatesneutral[candidatesneutral.size()-1]]);
		double finaldeltachn2 = deltaR(deltatranfr2chn);
		
		DISTRIB_P1MP2CHN->Fill((2*(p1-p2))/(p1+p2));

		if(finaldeltachn1 < 0.3 || finaldeltachn2 < 0.3){
			alo=true;
			if(finaldeltachn1 < finaldeltachn2 ){
				DISTRIB_IHCHN->Fill(track_ih_ampl[hscp_track_idx[indexcandidate]]);
				DISTRIB_IASCHN->Fill(track_ias_ampl[hscp_track_idx[indexcandidate]]);
				DISTRIB_P1_P2_CHN->Fill(p1,p2);
				DISTRIB_MET_pt_CHN->Fill(pfmet_pt[0], gen_pt[candidatesrh[candidatesrh.size()-1]]);// PT of charged candidate
			}
			else{
				DISTRIB_MET_pt_CHN->Fill(pfmet_pt[0], gen_pt[candidatesrh[candidatesneutral.size()-1]]);
			}
		}
		DISTRIB_PT1_PT2_CHN->Fill(gen_pt[candidatesrh[candidatesrh.size()-1]],gen_pt[candidatesneutral[candidatesneutral.size()-1]]);

		
		trigEff_presel.FindTurnOn(1,trig1,pfmet_pt[0]);
		
	}


	//*******************************CHARGED + CHARGED*******************************
	//*******************************************************************************

	else if(candidatesrh.size() == 2 && candidatesneutral.size() == 0){
		//*********** P of charged candidate 1 ***************
		double p1chch = (gen_pt[candidatesrh[candidatesrh.size()-1]] * cosh(gen_eta[candidatesrh[candidatesrh.size()-1]]));
		//*********** P of charged candidate 2 ***************
		double p2chch = (gen_pt[candidatesrh[candidatesrh.size()-2]] * cosh(gen_eta[candidatesrh[candidatesrh.size()-2]]));


		DISTRIB_MET_CHCH->Fill(pfmet_pt[0]);

		DISTRIB_P1MP2CHCH->Fill((2*(p1chch-p2chch))/(p1chch+p2chch));
		DISTRIB_PT1_PT2_CHCH->Fill(gen_pt[candidatesrh[candidatesrh.size()-1]],gen_pt[candidatesrh[candidatesrh.size()-2]]);
		DISTRIB_P1_P2_CHCH->Fill(p1chch,p2chch);
		
		nbchch+=1;
		double deltatranfr1 = deltaR2(track_eta[hscp_track_idx[indexcandidate]], track_phi[hscp_track_idx[indexcandidate]], gen_eta[candidatesrh[candidatesrh.size()-1]], gen_phi[candidatesrh[candidatesrh.size()-1]]);
		double finaldelta1 = deltaR(deltatranfr1);

		double deltatranfr2 = deltaR2(track_eta[hscp_track_idx[indexcandidate]], track_phi[hscp_track_idx[indexcandidate]], gen_eta[candidatesrh[candidatesrh.size()-2]], gen_phi[candidatesrh[candidatesrh.size()-2]]);
		double finaldelta2 = deltaR(deltatranfr2);			

		poverm1 = ((gen_pt[candidatesrh[candidatesrh.size()-1]] * cosh(gen_eta[candidatesrh[candidatesrh.size()-1]]))/TheorMass);
		poverm2 = ((gen_pt[candidatesrh[candidatesrh.size()-2]] * cosh(gen_eta[candidatesrh[candidatesrh.size()-2]]))/TheorMass);

		// Need help sorting this out
		if(finaldelta1 < 0.3 || finaldelta2 < 0.3){
			alo=true;
			DISTRIB_IHCHCH->Fill(track_ih_ampl[hscp_track_idx[indexcandidate]]);
			DISTRIB_IASCHCH->Fill(track_ias_ampl[hscp_track_idx[indexcandidate]]);
			DISTRIB_P1_P2_CHCH->Fill(p1chch,p2chch);

			

			if(finaldelta1 < finaldelta2 ){
				DISTRIB_MET_pt_CHCH->Fill(pfmet_pt[0], gen_pt[candidatesrh[candidatesrh.size()-1]]);
			}
			else{
				DISTRIB_MET_pt_CHCH->Fill(pfmet_pt[0], gen_pt[candidatesrh[candidatesrh.size()-2]]);
			}
		}


		trigEff_presel.FindTurnOn(0,trig1,pfmet_pt[0]);

	}
	
	if(alo==false && alo2 == false){
		//cout << "no track matched any gluino" << endl;
	}
	candidatesrh.clear();
	candidatesneutral.clear();
	candidatesdoublech.clear();
}

double AnaEff::deltaR2(float track_eta,float track_phi, float muon_eta, float muon_phi){
	float dp = std::abs(track_phi - muon_phi);
	if (dp > M_PI){
		dp -= 2.0 * M_PI;
	}
	return (track_eta - muon_eta)*(track_eta - muon_eta) + dp * dp;

}

double AnaEff::deltaR(double delta) {
	return std::sqrt(delta);
}


int main(){

	AnaEff ana;
	ana.Loop();
	
}
