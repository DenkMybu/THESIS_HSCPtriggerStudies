#define skelet_cxx
#include "Skelet.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <array>
#include <cstdlib>
#include <TLorentzVector.h>
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

const double TheorMass = 2600;

const double EPSILON = 1.0e-15;
 
void AnaEff::Loop(){
	Long64_t nentries = fChain->GetEntriesFast();
	Long64_t nbytes = 0, nb = 0, nbi = 0;
	Long64_t initializing = LoadTree(0);
	if (initializing < 0) cout << "Aborted"<< endl;
	nbi = fChain->GetEntry(initializing);   nbytes += nbi;
	cout << "Number of triggers for this file  : " << ntrigger << " , number of events : " << nentries << endl;

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

	DISTRIB_IH = new TH1D ("DISTRIB_IH", " IH ", 200, 0 , 20);
	DISTRIB_IH->GetXaxis()->SetTitle("Ih");
	DISTRIB_IH->GetYaxis()->SetTitle("# HSCP");
	
	DISTRIB_IH_NOPRESEL = new TH1D ("DISTRIB_IH_NOPRESEL", " IH_nopresel ", 200, 0 , 20);
	DISTRIB_IH_NOPRESEL->GetXaxis()->SetTitle("Ih");
	DISTRIB_IH_NOPRESEL->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_IH_PRESEL = new TH1D ("DISTRIB_IH_PRESEL", " IH_presel ", 200, 0 ,20);
	DISTRIB_IH_PRESEL->GetXaxis()->SetTitle("Ih");
	DISTRIB_IH_PRESEL->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_P_NOPRESEL = new TH1D ("DISTRIB_P_NOPRESEL", " P_nopresel", 400, 0 , 8000);
	DISTRIB_P_NOPRESEL->GetXaxis()->SetTitle("p [GeV]");
	DISTRIB_P_NOPRESEL->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_P_PRESEL = new TH1D ("DISTRIB_P_PRESEL", " P_presel ", 400, 0 , 8000);
	DISTRIB_P_PRESEL->GetXaxis()->SetTitle("p [GeV]");
	DISTRIB_P_PRESEL->GetYaxis()->SetTitle("# HSCP");

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

	DISTRIB_METNOSEL_TRIGGER = new TH1D("DISTRIB_METNOSEL_TRIGGER", "( MET )", 100,0,4000);
	DISTRIB_METNOSEL_TRIGGER->GetXaxis()->SetTitle("MET [GeV]");
	DISTRIB_METNOSEL_TRIGGER->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_METPRESEL = new TH1D("DISTRIB_METPRESEL", "( MET )", 100,0,4000);
	DISTRIB_METPRESEL->GetXaxis()->SetTitle("MET [GeV]");
	DISTRIB_METPRESEL->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_METPRESEL_TRIGGER = new TH1D("DISTRIB_METPRESEL_TRIGGER", "( MET )", 100,0,4000);
	DISTRIB_METPRESEL_TRIGGER->GetXaxis()->SetTitle("MET [GeV]");
	DISTRIB_METPRESEL_TRIGGER->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_METSEL = new TH1D("DISTRIB_METSEL", "( MET )", 100,0,4000);
	DISTRIB_METSEL->GetXaxis()->SetTitle("MET [GeV]");
	DISTRIB_METSEL->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_METSEL_TRIGGER = new TH1D("DISTRIB_METSEL_TRIGGER", "( MET )", 100,0,4000);
	DISTRIB_METSEL_TRIGGER->GetXaxis()->SetTitle("MET [GeV]");
	DISTRIB_METSEL_TRIGGER->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_METNOSEL_CHN = new TH1D("DISTRIB_METNOSEL_CHN", "( MET )", 100,0,4000);
	DISTRIB_METNOSEL_CHN->GetXaxis()->SetTitle("MET [GeV]");
	DISTRIB_METNOSEL_CHN->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_METPRESEL_CHN = new TH1D("DISTRIB_METPRESEL_CHN", "( MET )", 100,0,4000);
	DISTRIB_METPRESEL_CHN->GetXaxis()->SetTitle("MET [GeV]");
	DISTRIB_METPRESEL_CHN->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_METSEL_CHN = new TH1D("DISTRIB_METSEL_CHN", "( MET )", 100,0,4000);
	DISTRIB_METSEL_CHN->GetXaxis()->SetTitle("MET [GeV]");
	DISTRIB_METSEL_CHN->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_METNOSEL_CHCH = new TH1D("DISTRIB_METNOSEL_CHCH", "( MET )", 100,0,4000);
	DISTRIB_METNOSEL_CHCH->GetXaxis()->SetTitle("MET [GeV]");
	DISTRIB_METNOSEL_CHCH->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_METPRESEL_CHCH = new TH1D("DISTRIB_METPRESEL_CHCH", "( MET )", 100,0,4000);
	DISTRIB_METPRESEL_CHCH->GetXaxis()->SetTitle("MET [GeV]");
	DISTRIB_METPRESEL_CHCH->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_METSEL_CHCH = new TH1D("DISTRIB_METSEL_CHCH", "( MET )", 100,0,4000);
	DISTRIB_METSEL_CHCH->GetXaxis()->SetTitle("MET [GeV]");
	DISTRIB_METSEL_CHCH->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_DELTARN_CHN = new TH1D("DISTRIB_DELTARN_CHN", "( #Delta R )", 100,0,2);
	DISTRIB_DELTARN_CHN->GetXaxis()->SetTitle("#Delta R");
	DISTRIB_DELTARN_CHN->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_DELTARCH_CHN = new TH1D("DISTRIB_DELTARCH_CHN", "( #Delta R )", 100,0,2);
	DISTRIB_DELTARCH_CHN->GetXaxis()->SetTitle("#Delta R");
	DISTRIB_DELTARCH_CHN->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_DELTAR_ALL = new TH1D("DISTRIB_DELTAR_ALL", "( #Delta R )", 100,0,2);
	DISTRIB_DELTAR_ALL->GetXaxis()->SetTitle("#Delta R");
	DISTRIB_DELTAR_ALL->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_DELTAR_MU_CAND = new TH1D("DISTRIB_DELTAR_MU_CAND", "( #Delta R )", 1000,0,1); //bin problem ?
	DISTRIB_DELTAR_MU_CAND->GetXaxis()->SetTitle("#Delta R muon-candidate");
	DISTRIB_DELTAR_MU_CAND->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_ETA_DCH = new TH1D("DISTRIB_ETA_DCH", "( ETA dch )", 100, -3, 3);
	DISTRIB_ETA_DCH->GetXaxis()->SetTitle(" #Eta ");
	DISTRIB_ETA_DCH->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_MET_NN = new TH1D ("DISTRIB_MET_NN", " ( MET NN) " , 100,0,4000);
	DISTRIB_MET_NN->GetXaxis()->SetTitle("MET (GeV)");
	DISTRIB_MET_NN->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_P1MP2CHCH = new TH1D ("DISTRIB_P1MP2CHCH", "P1MP2CHCH", 100, -5, 5);
	DISTRIB_P1MP2CHCH->GetXaxis()->SetTitle("2*(p1 - p2) / (p1 + p2)");
	DISTRIB_P1MP2CHCH->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_P1MP2CHN = new TH1D ("DISTRIB_P1MP2CHN", "P1MP2CHN", 100, -5, 5);
	DISTRIB_P1MP2CHN->GetXaxis()->SetTitle("2*(p1 - p2) / (p1 + p2)");
	DISTRIB_P1MP2CHN->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_PT1MPT2CHCH = new TH1D ("DISTRIB_PT1MPT2CHCH", "PT1MPT2CHCH", 100, -5, 5);
	DISTRIB_PT1MPT2CHCH->GetXaxis()->SetTitle("2*(pt1 - pt2) / (pt1 + pt2)");
	DISTRIB_PT1MPT2CHCH->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_PT1MPT2CHN = new TH1D ("DISTRIB_PT1MPT2CHN", "PT1MPT2CHN", 100, -5, 5);
	DISTRIB_PT1MPT2CHN->GetXaxis()->SetTitle("2*(pt1 - pt2) / (pt1 + pt2)");
	DISTRIB_PT1MPT2CHN->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_ANGLE_RAD = new TH1D ("DISTRIB_ANGLE_RAD", "Angle between 1 & 2", 100, -5, 5);
	DISTRIB_ANGLE_RAD->GetXaxis()->SetTitle("Angle [rad]");
	DISTRIB_ANGLE_RAD->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_POVERMN_CHN = new TH1D ("DISTRIB_POVERMN_CHN", "P/m of neutral candidate in CH-N", 600 , 0 , 3);
	DISTRIB_POVERMN_CHN->GetXaxis()->SetTitle("p/m = #beta #gamma");
	DISTRIB_POVERMN_CHN->GetYaxis()->SetTitle("# Neutral R-hadrons");

	DISTRIB_POVERMCH_CHN = new TH1D ("DISTRIB_POVERMCH_CHN", "P/m of charged candidate in CH-N", 600 , 0 , 3);
	DISTRIB_POVERMCH_CHN->GetXaxis()->SetTitle("p/m = #beta #gamma");
	DISTRIB_POVERMCH_CHN->GetYaxis()->SetTitle("# Charged R-hadrons");

	DISTRIB_POVERM_ALL = new TH1D ("DISTRIB_POVERM_ALL", "P/m of all candidates", 600 , 0 , 3);
	DISTRIB_POVERM_ALL->GetXaxis()->SetTitle("p/m = #beta #gamma");
	DISTRIB_POVERM_ALL->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_POVERM_ALL_GEN = new TH1D ("DISTRIB_POVERM_ALL_GEN", "P/m of all candidates, gen p", 600 , 0 , 3);
	DISTRIB_POVERM_ALL_GEN->GetXaxis()->SetTitle("p/m = #beta #gamma");
	DISTRIB_POVERM_ALL_GEN->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_POVERM_ALL_STRAIGHT = new TH1D ("DISTRIB_POVERM_ALL_STRAIGHT", "P/m of all candidates in -0.1 < eta < 0.1", 600 , 0 , 3);
	DISTRIB_POVERM_ALL_STRAIGHT->GetXaxis()->SetTitle("p/m = #beta #gamma");
	DISTRIB_POVERM_ALL_STRAIGHT->GetYaxis()->SetTitle("# HSCP");

	DISTRIB_NMU_CHCH = new TH1D ("DISTRIB_NMU_CHCH", "Number of muons per event in CH-CH", 20 , 0 , 10);
	DISTRIB_NMU_CHCH->GetXaxis()->SetTitle("# muons per event");
	DISTRIB_NMU_CHCH->GetYaxis()->SetTitle("# events");

	DISTRIB_NHSCP_ALL = new TH1D ("DISTRIB_NHSCP_ALL", "Number of HSCP per event",10,0,5);
	DISTRIB_NHSCP_ALL->GetXaxis()->SetTitle("# HSCP per event");
	DISTRIB_NHSCP_ALL->GetYaxis()->SetTitle("# events");

	DISTRIB_DELTAR_TRACKERMU = new TH1D ("DISTRIB_DELTAR_TRACKERMU", "Delta R (muon-track) is_trackermuon in CH-CH", 100 , 0 , 2);
	DISTRIB_DELTAR_TRACKERMU->GetXaxis()->SetTitle("#Delta R between tracker muon and track");
	DISTRIB_DELTAR_TRACKERMU->GetYaxis()->SetTitle("# events");

	DISTRIB_DELTAR_GLOBALMU = new TH1D ("DISTRIB_DELTAR_GLOBALMU", "Delta R (muon-track) is_globalmuon in CH-CH", 100 , 0 , 2);
	DISTRIB_DELTAR_GLOBALMU->GetXaxis()->SetTitle("#Delta R between global muon and track");
	DISTRIB_DELTAR_GLOBALMU->GetYaxis()->SetTitle("# events");

	DISTRIB_MET_pt = new TH2D("DISTRIB_MET_pt", "Met vs pt overall", 600, 0, 4000, 600, 0, 4000);
	DISTRIB_MET_pt->GetXaxis()->SetTitle("Reco MET [GeV]");
	DISTRIB_MET_pt->GetYaxis()->SetTitle("Pt [GeV]");

	DISTRIB_MET_pt_CHN = new TH2D("DISTRIB_MET_pt_CHN", "Met vs pt chn", 600, 0, 4000, 600, 0, 4000);
	DISTRIB_MET_pt_CHN->GetXaxis()->SetTitle("Reco MET [GeV]");
	DISTRIB_MET_pt_CHN->GetYaxis()->SetTitle("Pt [GeV]");

	DISTRIB_MET_ptN_CHN = new TH2D("DISTRIB_MET_ptN_CHN", "Met vs pt of neutral in chn", 600, 0, 4000, 600, 0, 4000);
	DISTRIB_MET_ptN_CHN->GetXaxis()->SetTitle("Reco MET [GeV]");
	DISTRIB_MET_ptN_CHN->GetYaxis()->SetTitle("Pt [GeV]");


	DISTRIB_DEDX_POVERM_CHCH = new TH2D("DISTRIB_IH_POVERM_CHCH", "IH vs #beta #gamma in CH-CH",100, 0,10,100,0,5);
	DISTRIB_DEDX_POVERM_CHCH->GetYaxis()->SetTitle("IH");
	DISTRIB_DEDX_POVERM_CHCH->GetXaxis()->SetTitle("#beta #gamma");

	DISTRIB_DEDX_POVERM_CHN = new TH2D("DISTRIB_IH_POVERM_CHN", "IH vs #beta #gamma in CH-N",100, 0,10,100,0,5);
	DISTRIB_DEDX_POVERM_CHN->GetYaxis()->SetTitle("IH");
	DISTRIB_DEDX_POVERM_CHN->GetXaxis()->SetTitle("#beta #gamma");

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

	DISTRIB_TLV_MET = new TH2D("DISTRIB_TLV_MET", "TLV_MET_Com", 600 , 0 , 4000 , 600, 0 , 4000 );
	DISTRIB_TLV_MET->GetXaxis()->SetTitle("Reco pf_MET [GeV]");
	DISTRIB_TLV_MET->GetYaxis()->SetTitle("Reco pf_MET - MET from LorentzVector");

	DISTRIB_DELTAR_CH_VS_N = new TH2D("DISTRIB_DELTAR_CH_VS_N", "TLV_MET_Com", 100 , 0 , 2 , 100, 0 , 2 );
	DISTRIB_DELTAR_CH_VS_N->GetXaxis()->SetTitle("#Delta R of charged particle vs track");
	DISTRIB_DELTAR_CH_VS_N->GetYaxis()->SetTitle("#Delta R of neutral particle vs track");
	//*********************************************SUMW2****************************************************************
	//******************************************************************************************************************
	
	DISTRIB_NB_RHADRONS->Sumw2();
//
	DISTRIB_IAS->Sumw2();
	DISTRIB_IASCHN->Sumw2();
	DISTRIB_IASCHCH->Sumw2();
	DISTRIB_IASDCH->Sumw2();
	DISTRIB_IH->Sumw2();
	DISTRIB_IHCHN->Sumw2();
	DISTRIB_IHCHCH->Sumw2();
	DISTRIB_IHDCH->Sumw2();
	DISTRIB_METNOSEL->Sumw2();
	DISTRIB_METNOSEL_TRIGGER->Sumw2();
	DISTRIB_METSEL_TRIGGER->Sumw2();
	DISTRIB_METPRESEL_TRIGGER->Sumw2();
	DISTRIB_METPRESEL->Sumw2();
	DISTRIB_METSEL->Sumw2();
	DISTRIB_METNOSEL_CHN->Sumw2();
	DISTRIB_METPRESEL_CHN->Sumw2();
	DISTRIB_METSEL_CHN->Sumw2();
	DISTRIB_METNOSEL_CHCH->Sumw2();
	DISTRIB_METPRESEL_CHCH->Sumw2();
	DISTRIB_METSEL_CHCH->Sumw2();
	DISTRIB_DELTARN_CHN->Sumw2();
	DISTRIB_DELTARCH_CHN->Sumw2();
	DISTRIB_DELTAR_ALL->Sumw2();
	DISTRIB_DELTAR_MU_CAND->Sumw2();
	DISTRIB_DEDX_POVERM_CHN->Sumw2();
	DISTRIB_DEDX_POVERM_CHCH->Sumw2();
	DISTRIB_ETA_DCH->Sumw2();
	DISTRIB_MET_NN->Sumw2();
	DISTRIB_MET_pt->Sumw2();
	DISTRIB_MET_pt_CHN->Sumw2();
	DISTRIB_MET_pt_CHCH->Sumw2();
	DISTRIB_MET_ptN_CHN->Sumw2();
	DISTRIB_P1MP2CHCH->Sumw2();
	DISTRIB_P1MP2CHN->Sumw2();
	DISTRIB_PT1MPT2CHCH->Sumw2();
	DISTRIB_PT1MPT2CHN->Sumw2();
	DISTRIB_ANGLE_RAD->Sumw2();
	DISTRIB_POVERMN_CHN->Sumw2();
	DISTRIB_POVERMCH_CHN->Sumw2();
	DISTRIB_POVERM_ALL->Sumw2();
	DISTRIB_POVERM_ALL_GEN->Sumw2();
	DISTRIB_POVERM_ALL_STRAIGHT->Sumw2();
	DISTRIB_NMU_CHCH->Sumw2();
	DISTRIB_DELTAR_TRACKERMU->Sumw2();
	DISTRIB_DELTAR_GLOBALMU->Sumw2();
	DISTRIB_NHSCP_ALL->Sumw2();
	DISTRIB_PT1_PT2->Sumw2();
	DISTRIB_PT1_PT2_CHCH->Sumw2();
	DISTRIB_PT1_PT2_CHN->Sumw2();
	DISTRIB_PT1_PT2_NN->Sumw2();
	DISTRIB_P1_P2_CHN->Sumw2();
	DISTRIB_P1_P2_CHCH->Sumw2();
	DISTRIB_TLV_MET->Sumw2();
	DISTRIB_DELTAR_CH_VS_N->Sumw2();
	DISTRIB_P_NOPRESEL->Sumw2();
	DISTRIB_P_PRESEL->Sumw2();
	DISTRIB_IH_NOPRESEL->Sumw2();
	DISTRIB_IH_PRESEL->Sumw2();
	
	//******************************************************************************************************************
	//******************************************************************************************************************

	string NameList = "CompleteList", PrescaledList = "PrescaledList", ListAll = "ListOfAllTriggersEff", SubNum = "all", ExtRoot = ".root", ExtTxt = ".txt", Date="05_10_2021", Or = "LogicalOr", TransferTxt="AllInfos", TransferEff = "Eff", TransferZ = "EntriesFromZ", TransferW = "EntriesFromW", ErrorEffTransfer = "Error", TransferDistribZ = "DistribZpeak", TransferDistribW = "DistribWpeak", Data = "Gluino", DataType = Data + to_string(int(TheorMass)), test = "Test", dump = "dump_deltar", scenario = "Mode";

	string mode = "Both"; // To pick if you want to compute efficiencies for Both scenarios, CHCH (charged-charged) or CHN (charged-neutral)
	
	string EffScenario = TransferEff + scenario + mode + DataType + ExtTxt;

	string dumpfile = dump + DataType + ExtTxt;
	string teffFilename = test + DataType + ExtRoot;

	string StudyTxt = TransferTxt + DataType + Date;
	string NameOfTxt = StudyTxt + SubNum + ExtTxt;

	string StudyDistribZ = TransferDistribZ + DataType + Date;
	string distribvarZ = StudyDistribZ + SubNum + ExtRoot;
	

	string NameCompleteList = "ListeInteretTriggers";
	string NameListForType = NameCompleteList + DataType + ExtTxt;


	ReadFromTxt(NameListForType);
	trigEff_presel.LoadNoMap(triggerNames,1);
	
	int counter=0,counterasso=0,countertotasso=0,passedevent=0,passednosel=0,passedpresel=0,passedsel=0,nbofpairs=0,nbmuons=0,nbwrong=0,indexcandidate, indexcandidatenosel, indexcandidatesel;

	string trigger1="",trigger2="";
	trigEff_presel.InitTEff(teffFilename);
	cout << "Working on " << DataType << " , study will be on scenario " << mode << endl;
	posa.resize(triggerNames.size(), 0.0);
	/*for(int l = 0; l < triggerName->size(); l++){
			for(int i = 0; i<triggerNames.size();i++){
				if(triggerName->at(l) == triggerNames[i]){
					posa[i]=l;
					break;
				}
			}
	}*/
	Dump.open (dumpfile);
	cout << "nb entrees : " << nentries << endl;
	for (Long64_t jentry=0; jentry<nentries;jentry++){
		Long64_t ientry = LoadTree(jentry);
		if(jentry!=0 && jentry%1000==0) cout << "+1k" << " => " << jentry << " , "<<(jentry*1.0/nentries)*100 << " %" << endl;
		if (ientry < 0) break;
        	nb = fChain->GetEntry(jentry);   nbytes += nb;	
		counter+=1;
		DISTRIB_METNOSEL->Fill(pfmet_pt[0]);
		DISTRIB_NHSCP_ALL->Fill(nhscp);
		indexcandidate=Preselection();
		for(int ihs=0; ihs<nhscp;ihs++){
			DISTRIB_P_NOPRESEL->Fill(track_p[hscp_track_idx[ihs]]);
			DISTRIB_IH_NOPRESEL->Fill(track_ih_ampl[hscp_track_idx[ihs]]);
		}
		auto it = find(triggerName->begin(), triggerName->end(), "HLT_PFMET120_PFMHT120_IDTight_v16");
		auto index = distance(triggerName->begin(), it);
		if(it != triggerName->end()){
			if(passTrigger[index] == 1){
				DISTRIB_METNOSEL_TRIGGER->Fill(pfmet_pt[0]);
			}
		}
		if(indexcandidate!=64){
			DISTRIB_P_PRESEL->Fill(track_p[hscp_track_idx[indexcandidate]]);
			DISTRIB_IH_PRESEL->Fill(track_ih_ampl[hscp_track_idx[indexcandidate]]);
			DISTRIB_METPRESEL->Fill(pfmet_pt[0]);

			auto it = find(triggerName->begin(), triggerName->end(), "HLT_PFMET120_PFMHT120_IDTight_v16");
			auto index = distance(triggerName->begin(), it);
			if(it != triggerName->end()){
				if(passTrigger[index] == 1){
					DISTRIB_METPRESEL_TRIGGER->Fill(pfmet_pt[0]);
				}
			}

			passedpresel+=1;
			indexcandidatesel = Selection(indexcandidate);
			if(indexcandidatesel != 64){
				DISTRIB_POVERM_ALL->Fill(track_p[hscp_track_idx[indexcandidatesel]]*1.0/TheorMass);
				if(track_eta[hscp_track_idx[indexcandidatesel]] <= 0.1 && track_eta[hscp_track_idx[indexcandidatesel]] >= -0.1){
					DISTRIB_POVERM_ALL_STRAIGHT->Fill(track_p[hscp_track_idx[indexcandidatesel]]*1.0/TheorMass);
				}
				DISTRIB_METSEL->Fill(pfmet_pt[0]);
				auto it = find(triggerName->begin(), triggerName->end(), "HLT_PFMET120_PFMHT120_IDTight_v16");
				auto index = distance(triggerName->begin(), it);
				if(it != triggerName->end()){
					if(passTrigger[index] == 1){
						DISTRIB_METSEL_TRIGGER->Fill(pfmet_pt[0]);
					}
				}

				passedevent+=1;
				DISTRIB_IAS->Fill(track_ias_ampl[hscp_track_idx[indexcandidatesel]]);
				
				/* TEST TIME OPTIMIZER, uncomment line 319 and remove function FillTEff(indexcandidatesel) : same output (?) with 20% less time consumed
				for(int i=0; i < posa.size(); i++){
					for(int j=0; j < triggerNames.size(); j++){
						if(triggerNames[j] == triggerName->at(posa[i])){
							trigEff_presel.FillNoMap(triggerNames[j], passTrigger[posa[i]], pfmet_pt[0]);
							//cout << triggerNames[i] << " has trigger value " << passTrigger[j] << endl;
							trig.push_back(make_pair(triggerNames[j], passTrigger[posa[i]]));
							break;
							
						}
						else{

							cout << "+1 event where triggernames do not match expected ints" << endl;
						}
					}

				}*/

				CountZones(track_p[hscp_track_idx[indexcandidatesel]]);
				TrackRhadron();
				if(mode == "Both"){
					FillTEff(indexcandidatesel);
					trigEff_presel.FillTrigEff(trig);
					trig.clear();
				}
				AssoGenId(indexcandidatesel, int(jentry), mode);
				trig.clear();
			
			}
		}

	}

	
	trigEff_presel.Compute(EffScenario);
	trigEff_presel.WritePlots("","");

	ofstream InfosData;
	InfosData.open (NameOfTxt);
	
	//*******************************TERMINAL OUTPUT*********************************
	
	cout << "--------------------- RHADRONS ---------------- "  << endl;
	cout << " There was " << nbtot << " events, " << nbchn << " charged + neutral and" << nbchch << " charged + charged" << endl;
	cout << " Charged-Charged : " << nbchch << " / " << nbtot << " = " << nbchch*1.0/nbtot <<  endl;
	cout << " Neutral-Charged : " << nbchn << " / " << nbtot << " = "  <<  nbchn*1.0/nbtot << endl;
	cout << " Neutral-X : " << nbnn << " / " << nbtot << " = "  <<  nbnn*1.0/nbtot << endl;
	cout << "Double charged R-hadrons :  " << nbtch << " / " << nbtot << " = " << nbtch*1.0/nbtot << endl;

	

	//*********************************TXT OUTPUT***********************************
	InfosData << "Working on " << DataType << " in " << mode << " scenario \n" << endl;
	InfosData << "# events : " << nentries << " , # passing preselection : " << passedpresel << " ,# passing selection IAS > 0.2 ," << passedevent << ", should equal nbtot = " << nbtot << " ¦¦ nb missmatched : " << nbmissmatch << endl;
	InfosData << "*******************************SCENARIOS*******************************" << "\n" << endl;
	InfosData << " # Charged-Charged : " << nbchch << " / " << nbtot << " = " << (nbchch*1.0/nbtot)*100 << " % " << endl;
	InfosData << " # Charged-Neutral : " << nbchn << " / " << nbtot << " = " << (nbchn*1.0/nbtot)*100 << " % " << endl;
	InfosData << " # Neutral-Neutral : " << nbnn << " / " << nbtot << " = " << (nbnn*1.0/nbtot)*100 << " % " << endl;
	InfosData << " # Neutral-X : " << nbnx << " / " << nbtot << " = " << (nbnx*1.0/nbtot)*100 << " % " << endl;
	InfosData << " # Double charged - X " << nbtch << " / " << nbtot << " = " << (nbtch*1.0/nbtot)*100 << " % " << "\n\n" << endl;
	InfosData << "*******************************# candidates in each zone in p/m*******************************" << "\n" << endl;
	InfosData << " p/m < 0.1 : " << (nbinfpom*1.0/(nbinfpom+nbinpom+nbsuppom)*1.0)*100 << " % " << endl;
	InfosData << " 0.1 < p/m < 0.9 : " <<  (nbinpom*1.0/(nbinfpom+nbinpom+nbsuppom)*1.0)*100 << " % " << endl;
	InfosData << " p/m > 0.9 : " << (nbsuppom*1.0/(nbinfpom+nbinpom+nbsuppom)*1.0)*100 << " % " << "\n\n" << endl;
	InfosData << "***********************# candidates with Delta R (muon-track)************************" << "\n\n" << endl;
	InfosData << "----------- CHARGED - CHARGED -----------" << "\n" << endl;
	if(nmatchingibchch == 0){
		InfosData << " Scenario charged-charged not computed \n" << endl;
	}
	else{
		InfosData << " There was " << nbdeltarnullchch << " events where Delta R (muon-track) < e-15 ( = 0) : " << (nbdeltarnullchch*1.0/(nbdeltarnullchch+nmuonmatchingchch+nmatchingibchch))*100 << " % " << endl;
		InfosData << " There was " << nmuonmatchingchch << " events where smallest Delta R > 0.3 : " << (nmuonmatchingchch*1.0/(nbdeltarnullchch+nmuonmatchingchch+nmatchingibchch))*100 << " % " << endl;
		InfosData << " There was " << nmatchingibchch << " events where e-15 < Delta R < 0.3 : " << (nmatchingibchch*1.0/(nbdeltarnullchch+nmuonmatchingchch+nmatchingibchch))*100 << " % " << "\n" << endl;

	}
	InfosData << "----------- CHARGED - NEUTRAL -----------" << "\n" << endl;

	if(nmatchingibchn == 0){
		InfosData << " Scenario charged-neutral not computed \n" << endl;
	}
	else{
		InfosData << " There was " << nbdeltarnullchn << " events where Delta R (muon-track) < e-15 ( = 0) : "<< (nbdeltarnullchn*1.0/(nbdeltarnullchn+nmuonmatchingchn+nmatchingibchn))*100 << " % "<< endl;
		InfosData << " There was " << nmuonmatchingchn << " events where smallest Delta R > 0.3 : " << (nmuonmatchingchn*1.0/(nbdeltarnullchn+nmuonmatchingchn+nmatchingibchn))*100 << " % "<< endl;
		InfosData << " There was " << nmatchingibchn << " events where e-15 < Delta R < 0.3 : " << (nmatchingibchn*1.0/(nbdeltarnullchn+nmuonmatchingchn+nmatchingibchn))*100 << " % "<< endl;
	}
	
	InfosData.close();
	//******************************************************************************
	//******************************************************************************

	Dump << "There was " << nmissmuons << " CH-N events without any muons = " << (nmissmuons*1.0/nbchn)*100 << " % " << endl;
	Dump << "------------------------------------------Chain of r-hadrons ----------------------------------------------- \n\n" << endl;
	Dump << "In total, there was " << nbchain << " events where a r-hadron chain was followed, and " << nbchainmiss << " where there was no obvious chain. We identified " << (nbchain*1.0/(nbchainmiss+nbchain))*100 << " % " << endl;
	Dump.close();
	//******************************************************************************


	

	distrib = new TFile(distribvarZ.c_str(),"RECREATE");
	
	distrib->cd();

	//********************************WRITING THXD**********************************

	DISTRIB_NB_RHADRONS->Write();
	DISTRIB_IAS->Write();
	DISTRIB_IASCHN->Write();
	DISTRIB_IASCHCH->Write();
	DISTRIB_IASDCH->Write();
	DISTRIB_IH->Write();
	DISTRIB_P_NOPRESEL->Write();
	DISTRIB_P_PRESEL->Write();
	DISTRIB_IH_NOPRESEL->Write();
	DISTRIB_IH_PRESEL->Write();
	DISTRIB_IHCHN->Write();
	DISTRIB_IHCHCH->Write();
	DISTRIB_IHDCH->Write();
	DISTRIB_METNOSEL->Write();
	DISTRIB_METNOSEL_TRIGGER->Write();
	DISTRIB_METSEL_TRIGGER->Write();
	DISTRIB_METPRESEL_TRIGGER->Write();
	DISTRIB_METPRESEL->Write();
	DISTRIB_METSEL->Write();
	DISTRIB_METNOSEL_CHN->Write();
	DISTRIB_METPRESEL_CHN->Write();
	DISTRIB_METSEL_CHN->Write();
	DISTRIB_METNOSEL_CHCH->Write();
	DISTRIB_METPRESEL_CHCH->Write();
	DISTRIB_METSEL_CHCH->Write();
	DISTRIB_DELTARN_CHN->Write();
	DISTRIB_DELTAR_ALL->Write();
	DISTRIB_DELTAR_CH_VS_N->Write();
	DISTRIB_DELTARCH_CHN->Write();
	DISTRIB_DELTAR_MU_CAND->Write();
	DISTRIB_P1_P2_CHN->Write();
	DISTRIB_P1_P2_CHCH->Write();
	DISTRIB_ETA_DCH->Write();
	DISTRIB_MET_NN->Write();
	DISTRIB_TLV_MET->Write();
	DISTRIB_DEDX_POVERM_CHN->Write();
	DISTRIB_DEDX_POVERM_CHCH->Write();
	DISTRIB_POVERMN_CHN->Write();
	DISTRIB_POVERMCH_CHN->Write();
	DISTRIB_POVERM_ALL->Write();
	DISTRIB_POVERM_ALL_GEN->Write();
	DISTRIB_POVERM_ALL_STRAIGHT->Write();
	DISTRIB_NMU_CHCH->Write();
	DISTRIB_DELTAR_TRACKERMU->Write();
	DISTRIB_DELTAR_GLOBALMU->Write();
	DISTRIB_NHSCP_ALL->Write();
	DISTRIB_MET_pt->Write();
	DISTRIB_MET_pt_CHCH->Write();
	DISTRIB_MET_pt_CHN->Write();
	DISTRIB_MET_ptN_CHN->Write();
	DISTRIB_P1MP2CHCH->Write();
	DISTRIB_P1MP2CHN->Write();
	DISTRIB_PT1MPT2CHCH->Write();
	DISTRIB_PT1MPT2CHN->Write();
	DISTRIB_ANGLE_RAD->Write();
	DISTRIB_PT1_PT2->Write();
	DISTRIB_PT1_PT2_CHCH->Write();
	DISTRIB_PT1_PT2_CHN->Write();
	DISTRIB_PT1_PT2_NN->Write();

	
	//******************************************************************************


	distrib->Close();
	cout << "Program terminated without any logic call out of bound" << endl;
}


//*********************************NO SELECTION*********************************

int AnaEff::NoSelection(){
	vector<int> positionsnosel;
	vector< pair<float, int > > Muonptnosel,HSCPptnosel,HSCPponmnosel;
	for(int ihs=0; ihs<nhscp;ihs++){
		positionsnosel.push_back(ihs); 
		HSCPptnosel.push_back(make_pair(track_pt[hscp_track_idx[ihs]],ihs));
		Muonptnosel.push_back(make_pair(muon_pt[ihs],ihs));
	}

	if(positionsnosel.size() != 0){
		sort(Muonptnosel.begin(),Muonptnosel.end());
		sort(HSCPptnosel.begin(),HSCPptnosel.end());
		return HSCPptnosel[HSCPptnosel.size()-1].second;
	}
	else{
		return 64;
	}

}

//*********************************PRESELECTION*********************************

int AnaEff::Preselection(){
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

		//deltaR requirement between track and hscp
		
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


int AnaEff::Selection(const int &indexcandidate){
	if(track_ias_ampl[hscp_track_idx[indexcandidate]] > 0.2){ 
		return indexcandidate;
	}
	else{
		return 64;
	}
	
}
//*******************************************************************************
//*******************************************************************************


//Following the chain of decay -> not possible for now 

void AnaEff::AssoGenId(const int &indexcandidate,const int &nbevent, const string &mode){
	TLorentzVector cand1,cand2,homemet;
	vector<int> candidatesrh,candidatesneutral,candidatesdoublech;
	int nbmothgen=0;
	for(int i=0; i < ngenpart ; i++){
		if(gen_moth_pdg[i] == 1000021){
			nbmothgen+=1;
		}
		//***************** CHARGED RHADRONS *****************
		for(int k = 0; k < indexpdgch.size() ; k++){
			if(abs(gen_pdg[i]) == indexpdgch[k]){
				if(gen_status[i] == 1){
					nbch+=1;
					candidatesrh.push_back(i);
				}
			}
		}
		//*****************************************************


		//***************** NEUTRAL RHADRONS *****************
		for(int j=0; j < indexpdgn.size(); j++){
			if(abs(gen_pdg[i]) == indexpdgn[j]){
				if(gen_status[i] == 1){
				 nbn+=1;
				 candidatesneutral.push_back(i);
				}
			}
		}
		//****************************************************

		for(int j=0; j < indexpdgch2.size(); j++){
			if(abs(gen_pdg[i]) == indexpdgch2[j]){
				if(gen_status[i] == 1){
					nbdch+=1;
					candidatesdoublech.push_back(i);
				}
			}
		}
	}


	if ((candidatesrh.size() + candidatesneutral.size() + candidatesdoublech.size()) != 2 ){
		nbmissmatch +=1;
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
	//***************** NEUTRAL + NEUTRAL *****************


	if(candidatesrh.size() == 0 && candidatesneutral.size() == 2){
		DISTRIB_MET_NN->Fill(pfmet_pt[0]);
		nbnn+=1;
		DISTRIB_PT1_PT2_NN->Fill(gen_pt[candidatesneutral[candidatesneutral.size()-1]],gen_pt[candidatesneutral[candidatesneutral.size()-2]]);
	}
	//***************** NEUTRAL + XXXXXXX *****************

	if( candidatesrh.size() == 0 && candidatesneutral.size() == 1 ){
		nbnx+=1;
	}

	//***************** CHARGED + NEUTRAL *****************

	if( candidatesrh.size() == 1 && candidatesneutral.size() == 1 ){
		nbchn+=1;
		//cout << "Charged + Neutral " << endl;
		vector<double> deltaRmuon;

		double pt1 = gen_pt[candidatesrh[candidatesrh.size()-1]], pt2 = gen_pt[candidatesneutral[candidatesneutral.size()-1]];
		double p1 = pt1 * cosh(gen_eta[candidatesrh[candidatesrh.size()-1]]);
		double p2 = pt2 * cosh(gen_eta[candidatesneutral[candidatesneutral.size()-1]]);
		DISTRIB_POVERM_ALL_GEN->Fill(p1*1.0/TheorMass);
		double finaldeltachn1 = deltaR(deltaR2(track_eta[hscp_track_idx[indexcandidate]], track_phi[hscp_track_idx[indexcandidate]], gen_eta[candidatesrh[candidatesrh.size()-1]], gen_phi[candidatesrh[candidatesrh.size()-1]]));
		double finaldeltachn2 = deltaR(deltaR2(track_eta[hscp_track_idx[indexcandidate]], track_phi[hscp_track_idx[indexcandidate]], gen_eta[candidatesneutral[candidatesneutral.size()-1]], gen_phi[candidatesneutral[candidatesneutral.size()-1]]));
		
		for(int k=0; k< nmuons; k++){
			deltaRmuon.push_back(deltaR(deltaR2(track_eta[hscp_track_idx[indexcandidate]], track_phi[hscp_track_idx[indexcandidate]],muon_eta[k], muon_phi[k])));	
		}
		if(nmuons == 0){
			nmissmuons+=1;
		}

		if(deltaRmuon.size()!=0){
			sort(deltaRmuon.begin(), deltaRmuon.end());
			DISTRIB_DELTAR_MU_CAND->Fill(deltaRmuon[0]);
			if(deltaRmuon[0] < EPSILON){
				nbdeltarnullchn+=1;
			}
	
			if(deltaRmuon[0] > 0.3){
				nmuonmatchingchn+=1;
			}
			if(deltaRmuon[0]>EPSILON && deltaRmuon[0] < 0.3 ){
				nmatchingibchn+=1;
			}
		}

		deltaRmuon.clear();
		if(finaldeltachn1 < 0.3 || finaldeltachn2 < 0.3){
			alo=true;
			if(finaldeltachn1 < finaldeltachn2 ){
				DISTRIB_IHCHN->Fill(track_ih_ampl[hscp_track_idx[indexcandidate]]);
				DISTRIB_IASCHN->Fill(track_ias_ampl[hscp_track_idx[indexcandidate]]);
				DISTRIB_P1_P2_CHN->Fill(p1,p2);
				DISTRIB_MET_pt_CHN->Fill(pfmet_pt[0], gen_pt[candidatesrh[candidatesrh.size()-1]]);//PT of charged candidate
				DISTRIB_MET_pt->Fill(pfmet_pt[0], gen_pt[candidatesrh[candidatesrh.size()-1]]);
			}
			else{
				DISTRIB_MET_pt_CHN->Fill(pfmet_pt[0], gen_pt[candidatesneutral[candidatesneutral.size()-1]]);
				DISTRIB_MET_pt->Fill(pfmet_pt[0], gen_pt[candidatesneutral[candidatesneutral.size()-1]]);
			}
		}

		DISTRIB_DELTAR_ALL->Fill(finaldeltachn1);
		DISTRIB_DELTAR_ALL->Fill(finaldeltachn2);
		DISTRIB_DELTARN_CHN->Fill(finaldeltachn2);
		DISTRIB_DELTARCH_CHN->Fill(finaldeltachn1);
		DISTRIB_DELTAR_CH_VS_N->Fill(finaldeltachn1,finaldeltachn2);
		DISTRIB_P1MP2CHN->Fill((2*(p1-p2))/(p1+p2));
		DISTRIB_PT1MPT2CHN->Fill((2*(pt1-pt2))/(pt1+pt2));
		DISTRIB_MET_ptN_CHN->Fill(pfmet_pt[0], gen_pt[candidatesneutral[candidatesneutral.size()-1]]);
		DISTRIB_POVERMCH_CHN->Fill(p1/TheorMass);
		DISTRIB_POVERMN_CHN->Fill(p2/TheorMass);
		DISTRIB_DEDX_POVERM_CHN->Fill((track_p[hscp_track_idx[indexcandidate]]*1.0/TheorMass),track_ih_ampl[hscp_track_idx[indexcandidate]]);
		DISTRIB_PT1_PT2_CHN->Fill(gen_pt[candidatesrh[candidatesrh.size()-1]],gen_pt[candidatesneutral[candidatesneutral.size()-1]]);
		
		cand1.SetPtEtaPhiM(gen_pt[candidatesrh[candidatesrh.size()-1]],gen_eta[candidatesrh[candidatesrh.size()-1]],gen_phi[candidatesrh[candidatesrh.size()-1]],TheorMass);
cand2.SetPtEtaPhiM(gen_pt[candidatesneutral[candidatesneutral.size()-1]],gen_eta[candidatesneutral[candidatesneutral.size()-1]],gen_phi[candidatesneutral[candidatesneutral.size()-1]],TheorMass);
		
		homemet = cand1 + cand2; 
		double v = homemet[0];
		double a = (gen_phi[candidatesrh[candidatesrh.size()-1]] - gen_phi[candidatesneutral[candidatesneutral.size()-1]]) ; 
		DISTRIB_TLV_MET->Fill(pfmet_pt[0],v);
		DISTRIB_ANGLE_RAD->Fill(a);
		DISTRIB_METSEL_CHN->Fill(pfmet_pt[0]);

		if(mode == "CHN"){
			FillTEff(indexcandidate);
			trigEff_presel.FillTrigEff(trig);
			trig.clear();
		}
	}


	//***************** CHARGED + CHARGED *****************

	if(candidatesrh.size() == 2 && candidatesneutral.size() == 0){
		//cout << "Charged + Charged " << endl;
		vector<double> deltaRmuonchch,deltaRtrackermuon;

		vector< pair<double,int> > deltaRmuonchchtest;
		double pt1chch = gen_pt[candidatesrh[candidatesrh.size()-1]], pt2chch = gen_pt[candidatesrh[candidatesrh.size()-2]]; 

		double p1chch = (pt1chch * cosh(gen_eta[candidatesrh[candidatesrh.size()-1]]));

		double p2chch = (pt2chch * cosh(gen_eta[candidatesrh[candidatesrh.size()-2]]));
		nbchch+=1;
		DISTRIB_POVERM_ALL_GEN->Fill(p1chch*1.0/TheorMass);
		DISTRIB_POVERM_ALL_GEN->Fill(p2chch*1.0/TheorMass);
		double finaldelta1 = deltaR(deltaR2(track_eta[hscp_track_idx[indexcandidate]], track_phi[hscp_track_idx[indexcandidate]], gen_eta[candidatesrh[candidatesrh.size()-1]], gen_phi[candidatesrh[candidatesrh.size()-1]]));

		double finaldelta2 = deltaR(deltaR2(track_eta[hscp_track_idx[indexcandidate]], track_phi[hscp_track_idx[indexcandidate]], gen_eta[candidatesrh[candidatesrh.size()-2]], gen_phi[candidatesrh[candidatesrh.size()-2]]));			

		
		poverm1 = ((gen_pt[candidatesrh[candidatesrh.size()-1]] * cosh(gen_eta[candidatesrh[candidatesrh.size()-1]]))/TheorMass);
		poverm2 = ((gen_pt[candidatesrh[candidatesrh.size()-2]] * cosh(gen_eta[candidatesrh[candidatesrh.size()-2]]))/TheorMass);
		DISTRIB_NMU_CHCH->Fill(nmuons);
	
		
		for(int i=0; i< nmuons; i++){
			deltaRmuonchch.push_back(deltaR(deltaR2(track_eta[hscp_track_idx[indexcandidate]], track_phi[hscp_track_idx[indexcandidate]],muon_eta[i], muon_phi[i])));
			deltaRmuonchchtest.push_back(make_pair(deltaR(deltaR2(track_eta[hscp_track_idx[indexcandidate]], track_phi[hscp_track_idx[indexcandidate]],muon_eta[i], muon_phi[i])),i));
		}
		if(deltaRmuonchchtest.size() != 0){
			sort(deltaRmuonchchtest.begin(), deltaRmuonchchtest.end());
			double deltaRmin = deltaRmuonchchtest[0].first;

			if(muon_isTrackerMuon[deltaRmuonchchtest[0].second]){
				DISTRIB_DELTAR_TRACKERMU->Fill(deltaRmin);
			}
			if(muon_isGlobalMuon[deltaRmuonchchtest[0].second]){
				DISTRIB_DELTAR_GLOBALMU->Fill(deltaRmuonchchtest[0].first);
			}
		}

		deltaRmuonchchtest.clear();
		if(deltaRmuonchch.size()!=0){
			sort(deltaRmuonchch.begin(), deltaRmuonchch.end());
			if(deltaRmuonchch[0] < EPSILON){
				nbdeltarnullchch+=1;
			}
			if(deltaRmuonchch[0] > 0.3){
				nmuonmatchingchch+=1;
			}
			if(deltaRmuonchch[0]>EPSILON && deltaRmuonchch[0] < 0.3 ){
				nmatchingibchch+=1;
			}
		}

		deltaRmuonchch.clear();
		deltaRtrackermuon.clear();

		if(finaldelta1 < 0.3 || finaldelta2 < 0.3){
			alo=true;
			DISTRIB_IHCHCH->Fill(track_ih_ampl[hscp_track_idx[indexcandidate]]);
			DISTRIB_IASCHCH->Fill(track_ias_ampl[hscp_track_idx[indexcandidate]]);
			DISTRIB_P1_P2_CHCH->Fill(p1chch,p2chch);

			if(finaldelta1 < finaldelta2 ){
				DISTRIB_MET_pt_CHCH->Fill(pfmet_pt[0], gen_pt[candidatesrh[candidatesrh.size()-1]]);
				DISTRIB_MET_pt->Fill(pfmet_pt[0], gen_pt[candidatesrh[candidatesrh.size()-1]]);
			}
			else{
				DISTRIB_MET_pt_CHCH->Fill(pfmet_pt[0], gen_pt[candidatesrh[candidatesrh.size()-2]]);
				DISTRIB_MET_pt->Fill(pfmet_pt[0], gen_pt[candidatesrh[candidatesrh.size()-2]]);
			}
		}

		DISTRIB_DEDX_POVERM_CHCH->Fill((track_p[hscp_track_idx[indexcandidate]]*1.0/TheorMass),track_ih_ampl[hscp_track_idx[indexcandidate]]);
		DISTRIB_P1MP2CHCH->Fill((2*(p1chch-p2chch))/(p1chch+p2chch));
		DISTRIB_PT1MPT2CHCH->Fill((2*(pt1chch-pt2chch))/(pt1chch+pt2chch));
		DISTRIB_PT1_PT2_CHCH->Fill(gen_pt[candidatesrh[candidatesrh.size()-1]],gen_pt[candidatesrh[candidatesrh.size()-2]]);
		DISTRIB_P1_P2_CHCH->Fill(p1chch,p2chch);
		DISTRIB_METSEL_CHCH->Fill(pfmet_pt[0]);

		if(mode == "CHCH"){		
			FillTEff(indexcandidate);
			trigEff_presel.FillTrigEff(trig);
			trig.clear();
		}
	}
	
	if(alo==false && alo2 == false){
		//cout << "no track matched any gluino" << endl;
	}

	
	candidatesrh.clear();
	candidatesneutral.clear();
	candidatesdoublech.clear();
	
}

void AnaEff::CountZones(const double &impulsion){
	if(impulsion*1.0/TheorMass < 0.1){
		nbinfpom+=1;
	}
	else if( impulsion*1.0/TheorMass < 0.9 && impulsion*1.0/TheorMass >0.1){
		nbinpom+=1;
	}
	else if( impulsion*1.0/TheorMass > 0.9){
		nbsuppom+=1;
	}
}

void AnaEff::FillTEff(const int &indexcandidate){
	for(int i = 0 ; i < triggerNames.size(); i++){
		for (int j = 0 ; j < triggerName->size() ; j++){
			if(triggerName->at(j) == triggerNames[i]){
				trigEff_presel.FillNoMap(triggerNames[i], passTrigger[j], pfmet_pt[0], 1.0 ,"MET");
				trigEff_presel.FillNoMap(triggerNames[i], passTrigger[j], (track_p[hscp_track_idx[indexcandidate]]/TheorMass), 1.0 ,"POM");
				trig.push_back(make_pair(triggerNames[i], passTrigger[j]));
				break;
			}

		}
	}
}


double AnaEff::deltaR2(const float &track_eta,const float &track_phi, const float &muon_eta, const float &muon_phi){
	float dp = std::abs(track_phi - muon_phi);
	if (dp > M_PI){
		dp -= 2.0 * M_PI;
	}
	return (track_eta - muon_eta)*(track_eta - muon_eta) + dp * dp;
}

double AnaEff::deltaR(const double &delta) {
	return std::sqrt(delta);
}


void AnaEff::TrackRhadron(){
	int tab[2];
	bool vtab[2] = {false}, flag = false,genflag=false;
	int gen,gen1,gen2;
	//cout << "New event with " << ngenpart << " particles " << endl;
	for(int i=0; i < ngenpart ; i++){
		double pc = gen_pt[i] * cosh(gen_eta[i]);
		if(gen_status[i] == 1){
			flag=true;
		}
		//cout << i << " gen : " << gen_pdg[i] << " , mother  : " << gen_moth_pdg[i] << " , status : " << gen_status[i] << " , p = : " << gen_pt[i] * cosh(gen_eta[i]) << endl;

		/*if(flag){
			cout << i << " gen : " << gen_pdg[i] << " , gen_moth : " << gen_moth_pdg[i] << " , status : " << gen_status[i] << " , p = pt * cosh(eta) : " << pc << endl;
		
		}*/

		//***************** CHARGED RHADRONS *****************
		//****************************************************		
		for(int k = 0; k < indexpdgch.size() ; k++){
			if(abs(gen_pdg[i]) == indexpdgch[k]){
				if(gen_status[i] == 1){
					nbch+=1;
					if(vtab[0] == false){
						tab[0] = i;
						vtab[0] = true;
						gen1 = gen_pdg[i];
					}
					if(vtab[0] == true){
						tab[1] = i;
						vtab[1] = true;
						gen2 = gen_pdg[i];
					}
					
				}
			}
		}
		//*****************************************************
		//*****************************************************

		//***************** NEUTRAL RHADRONS *****************
		//****************************************************
		for(int j=0; j < indexpdgn.size(); j++){
			if(abs(gen_pdg[i]) == indexpdgn[j]){
				if(gen_status[i] == 1){
					nbn+=1;
					if(vtab[0] == false){
						tab[0] = i;
						vtab[0] = true;
					}
					if(vtab[0] == true){
						tab[1]=i;
						vtab[1] = true;

					}
				}
			}
		}
		
	}
	bool yoi=false;
	//cout << " Our two interesting events are labelled : " << tab[0] << " with gen : " << gen1 << " and " << tab[1] << " with gen : " << gen2 << endl;
	for(int i=0; i< ngenpart;i++){
		if(genflag==false){
			for(int l=0;l<indexpdgch.size();l++){
				if(abs(gen_pdg[i]) == indexpdgch[l]){
					genflag = true;
					gen = abs(gen_pdg[i]);
					break;
				}
			}
		}
		
		if(abs(gen_moth_pdg[i]) == gen){
			gen = abs(gen_pdg[i]);
			yoi=true;
			cout << i << " gen : " << gen_pdg[i] << " , gen_moth : " << gen_moth_pdg[i] << " , status : " << gen_status[i] << " , p = pt * cosh(eta) : " << gen_pt[i] * cosh(gen_eta[i]) << endl;
		}
	
	}
	
	if(!yoi){
		nbchainmiss+=1;
	}
	if(yoi){
		nbchain+=1;
	}	
}

void AnaEff::ReadFromTxt(const string &NameListForType){
	ifstream ifile(NameListForType.c_str()); 
	string tmp;
	if(ifile.is_open()){
		while(getline(ifile,tmp)){
   			triggerNames.push_back(tmp);
		}
	}
	cout << triggerNames.size() << " triggers found in the entry list" << endl;
	ifile.close();
	//bool ReadFromTxt, return 1 if no problem
}

int main(){

	AnaEff ana;
	ana.Loop();
	
}
