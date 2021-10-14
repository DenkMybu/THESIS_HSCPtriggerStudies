#ifndef SKELET_H
#define SKELET_H


#include <vector>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <TTree.h>
//include our classes
#include "inc/Inc.h" 




using namespace std;


class AnaEff
{
public :
  
   //--------------------------------------
   //Data members
   //--------------------------------------

   //User variables


   TrigEff   trigEff_presel;// other methods from other .h classes

   //TrigEff   trigEff_selection_obs;

   //List of variables with ROOT dependencies
   
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain


  // Declaration of leaf types
   Int_t	runNumber;
   UInt_t	event;
   Int_t	npv;
   Int_t	ngoodpv;
   Int_t	ntrigger;
   Int_t	nhscp;
   Int_t	ndedxhits;

   Float_t	pfmet_pt[32]; //test

   Float_t	prescaleTrigger[1000];
   Bool_t	passTrigger[1000];
   vector<string>* triggerName;
   
   Bool_t       muon_isMediumMuon[32];

   Float_t	track_pt[33]; //[ntracks] augmenter la taille pour pas de overflow, it was 33
   Float_t      track_p[33];   
   Float_t	track_pterr[33];
   Int_t	hscp_track_idx[9];  //[nhscp] it was 9
   Int_t        ntracks;
   Int_t	ngenpart;

   Int_t	gen_pdg[451];
   Float_t	gen_pt[451];   //[ngenpart]
   Float_t	gen_eta[451];   //[ngenpart]
   Float_t	gen_phi[451];   //[ngenpart]
   Float_t	gen_mass[451];   //[ngenpart]
   Int_t	gen_moth_pdg[451]; //[ngenpart]
   Int_t	gen_status[451];

   Float_t	track_eta[33];
   Float_t	track_phi[33];
   Int_t	track_npixhits[33];
   Int_t	track_nvalidhits[33];
   Float_t	track_validfraction[33];
  
   Int_t	track_nhits[33];
   Float_t	track_dz[33];
   Float_t	track_dxy[33];
   Int_t	track_qual[33];
   Float_t	hscp_iso2_tk[9];
   Bool_t	muon_isTrackerMuon[32];
   Float_t      muon_comb_inversebeta[32];
   Float_t      track_ih_ampl[33];
   Float_t      track_ias_ampl[33];
   Float_t      muon_phi[32];
   Float_t      muon_eta[32];
   Float_t      muon_pt[32];
   Float_t      muon_p[32];
   Int_t	nmuons;
   Float_t      muon_isoR03_sumChargedHadronPt[32];
   Int_t        hscp_muon_idx[9];

    // List of branches
   TBranch        *b_runNumber;   //!
   TBranch        *b_event;   //!
   TBranch        *b_npv;   //!
   TBranch        *b_ngoodpv;   //!
   TBranch        *b_ntrigger; //!
   TBranch        *b_prescaleTrigger;
   TBranch	  *b_triggerName;
   TBranch        *b_passTrigger; //!
   TBranch        *b_track_pt;   //!
   TBranch        *b_track_pterr; //!
   TBranch        *b_hscp_track_idx;   //!
   TBranch        *b_nhscp;  //!
   TBranch        *b_ngenpart;   //!
   TBranch        *b_gen_moth_pdg;   //!
   
   TBranch        *b_gen_status;
   TBranch        *b_track_nhits;
   TBranch        *b_pfmet_pt; // !
   TBranch        *b_track_eta; //!
   TBranch        *b_track_npixhits; //!
   TBranch        *b_track_nvalidhits;
   TBranch        *b_track_validfraction;
   TBranch        *b_ndedxhits;
   TBranch        *b_track_dz;
   TBranch        *b_track_dxy;
   TBranch        *b_track_qual;
   TBranch        *b_hscp_iso2_tk;
   TBranch        *b_muon_isTrackerMuon;
   TBranch        *b_muon_comb_inversebeta;
   TBranch        *b_track_p;
   TBranch        *b_track_ih_ampl;
   TBranch        *b_track_ias_ampl;
   TBranch        *b_muon_eta;   //!
   TBranch        *b_muon_phi;
   TBranch        *b_muon_pt;
   TBranch        *b_muon_p;
   TBranch        *b_nmuons;
   TBranch        *b_muon_isoR03_sumChargedHadronPt;
   TBranch        *b_track_phi;
   TBranch        *b_ntracks;
   TBranch        *b_hscp_muon_idx;
   TBranch        *b_muon_isMediumMuon;
   TBranch        *b_gen_pdg;   //!
   TBranch        *b_gen_pt;   //!
   TBranch        *b_gen_eta;   //!
   TBranch        *b_gen_phi;   //!
   TBranch        *b_gen_mass;   //!
   //--------------------------------------
   // 		   METHODS
   //--------------------------------------

   AnaEff(TTree *tree=0);
   virtual ~AnaEff();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual int      Preselection();
   virtual int      Selection(int indexcandidate);
   virtual double   deltaR2(float track_eta,float track_phi, float muon_eta, float muon_phi);
   virtual double   deltaR(double delta);
   virtual void	    AssoGenId(int indexcandidate,bool trig1);

   
private :

  TFile* distrib;
  Int_t nbchch=0,nbchn=0,nbnn=0,nbdch=0,nbtot=0,nbn=0,nbch=0, nbtch=0, nbnx=0,nbmissmatch=0;
  Double_t p1=0,p2=0,eta1=0,eta2=0,pt1=0,pt2=0,poverm1=0,poverm2=0;
  bool trig1,trig2;

  //*************************************** TH1D compiled by main class *****************************************************
  TH1D* DISTRIB_NB_RHADRONS;

  TH1D* DISTRIB_IAS;

  TH1D* DISTRIB_IASCHN;
  TH1D* DISTRIB_IASCHCH;
  TH1D* DISTRIB_IASDCH;

  TH1D* DISTRIB_IH;

  TH1D* DISTRIB_IHCHN;
  TH1D* DISTRIB_IHCHCH;
  TH1D* DISTRIB_IHDCH;

  TH1D* DISTRIB_METNOSEL;
  TH1D* DISTRIB_METPRESEL;
  TH1D* DISTRIB_METSEL;

  TH1D* DISTRIB_ETA_DCH;
  TH1D* DISTRIB_MET_CHN;
  TH1D* DISTRIB_MET_CHCH;
  TH1D* DISTRIB_MET_NN;

  TH1D* DISTRIB_P1MP2CHCH;
  TH1D* DISTRIB_P1MP2CHN;
  TH1D* DISTRIB_PT1MPT2CHCH;
  TH1D* DISTRIB_PT1MPT2CHN;

  TH1D* DISTRIB_ANGLE_RAD;
  TH1D* DISTRIB_POVERMN_CHN;
  TH1D* DISTRIB_POVERMCH_CHN;
  //*************************************************************************************************************************


  //*************************************** TH2D compiled by main class *****************************************************
  TH2D* DISTRIB_P1_P2_CHN;
  TH2D* DISTRIB_P1_P2_CHCH;

  TH2D* DISTRIB_PT1_PT2;
  TH2D* DISTRIB_PT1_PT2_CHCH;
  TH2D* DISTRIB_PT1_PT2_CHN;
  TH2D* DISTRIB_PT1_PT2_NN;
	
  TH2D* DISTRIB_TLV_MET;

  TH2D* DISTRIB_MET_pt_CHCH;
  TH2D* DISTRIB_MET_pt_CHN;
  TH2D* DISTRIB_MET_ptN_CHN;


  //*************************************************************************************************************************
};


#endif

#ifdef skelet_cxx

AnaEff::AnaEff(TTree *tree) : fChain(0) //construct
{
	distrib=0;

	DISTRIB_NB_RHADRONS=0;

	DISTRIB_IAS=0;
	DISTRIB_IASCHN=0;
	DISTRIB_IASCHCH=0;
	DISTRIB_IASDCH=0;

	


	DISTRIB_IH=0;
	DISTRIB_IHCHN=0;
	DISTRIB_IHCHCH=0;
	DISTRIB_IHDCH=0;

	DISTRIB_METSEL=0;
	DISTRIB_METPRESEL=0;
	DISTRIB_METNOSEL=0;

	DISTRIB_ETA_DCH=0;

	DISTRIB_MET_CHN=0;
	DISTRIB_MET_CHCH=0;
	DISTRIB_MET_NN=0;

	DISTRIB_TLV_MET=0;

	DISTRIB_P1MP2CHCH=0;
	DISTRIB_P1MP2CHN=0;
	DISTRIB_PT1MPT2CHCH=0;
	DISTRIB_PT1MPT2CHN=0;


	DISTRIB_ANGLE_RAD=0;

	DISTRIB_POVERMN_CHN=0;
	DISTRIB_POVERMCH_CHN=0;

	DISTRIB_P1_P2_CHN=0;
	DISTRIB_P1_P2_CHCH=0;

	DISTRIB_PT1_PT2=0;
	DISTRIB_PT1_PT2_CHCH=0;
	DISTRIB_PT1_PT2_CHN=0;
	DISTRIB_PT1_PT2_NN=0;

	DISTRIB_MET_pt_CHCH=0;
	DISTRIB_MET_pt_CHN=0;
	DISTRIB_MET_ptN_CHN=0;

	triggerName = 0;
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
	if (tree == 0) {
		TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/opt/sbg/cms/safe1/cms/rhaeberl/CMSSW_10_6_2/src/HSCPtriggerStudies/all_stop2400.root"); //opt/sbg/cms/ui3_data1/dapparu/HSCP/Production/prodMarch2021_CMSSW_10_6_2/HSCPgluino_M-1600_TuneCP5_13TeV-pythia8/MC17_Gluino1600_runv3/210324_135858/0000

		if (!f || !f->IsOpen()) {
			f = new TFile("/opt/sbg/cms/safe1/cms/rhaeberl/CMSSW_10_6_2/src/HSCPtriggerStudies/all_stop2400.root");
		}
		
	
		TDirectory * dir = (TDirectory*)f->Get("/opt/sbg/cms/safe1/cms/rhaeberl/CMSSW_10_6_2/src/HSCPtriggerStudies/all_stop2400.root:/stage"); 
		dir->GetObject("ttree",tree);
		
// /opt/sbg/cms/safe1/cms/rhaeberl/CMSSW_10_6_2/src/HSCPtriggerStudies/all_stop2400.root
// /opt/sbg/cms/ui3_data1/dapparu/HSCP/Production/prodMarch2021_CMSSW_10_6_2/HSCPgluino_M-2000_TuneCP5_13TeV-pythia8/MC17_Gluino2000/210316_095038/0000/nt_mc_aod_1.root

  	 }
  
   //passTrigger = new bool[ntrigger];
   Init(tree);

}



AnaEff::~AnaEff() //deconstruct
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
   
  if(!distrib){
   	delete distrib;
  }

  if(!DISTRIB_NB_RHADRONS){
   	delete DISTRIB_NB_RHADRONS;
  }

  if(!DISTRIB_IAS){
   	delete DISTRIB_IAS;
  }
  if(!DISTRIB_IASCHN){
   	delete DISTRIB_IASCHN;
  }
  if(!DISTRIB_IASCHCH){
   	delete DISTRIB_IASCHCH;
  }
  if(!DISTRIB_IASDCH){
   	delete DISTRIB_IASDCH;
  }


  if(!DISTRIB_IH){
   	delete DISTRIB_IH;
  }
  if(!DISTRIB_IHCHN){
   	delete DISTRIB_IHCHN;
  }
  if(!DISTRIB_IHCHCH){
   	delete DISTRIB_IHCHCH;
  }
  if(!DISTRIB_IHDCH){
  	delete DISTRIB_IHDCH;
  }
  if(!DISTRIB_METSEL){
   	delete DISTRIB_METSEL;
  }
  if(!DISTRIB_METNOSEL){
   	delete DISTRIB_METNOSEL;
  }
  if(!DISTRIB_METPRESEL){
   	delete DISTRIB_METPRESEL;
  }
  if(!DISTRIB_ETA_DCH){
  	delete DISTRIB_ETA_DCH;
  }
  if(!DISTRIB_MET_CHN){
  	delete DISTRIB_MET_CHN;
  }
  if(!DISTRIB_MET_NN){
  	delete DISTRIB_MET_NN;
  }
  if(!DISTRIB_MET_CHCH){
  	delete DISTRIB_MET_CHCH;
  }

  if(!DISTRIB_P1MP2CHCH){
  	delete DISTRIB_P1MP2CHCH;
  }
  if(!DISTRIB_P1MP2CHN){
  	delete DISTRIB_P1MP2CHN;
  }	
  if(!DISTRIB_PT1MPT2CHCH){
  	delete DISTRIB_PT1MPT2CHCH;
  }
  if(!DISTRIB_PT1MPT2CHN){
  	delete DISTRIB_PT1MPT2CHN;
  }


  if(!DISTRIB_POVERMN_CHN){
   	delete DISTRIB_POVERMN_CHN;
  }
  if(!DISTRIB_POVERMCH_CHN){
   	delete DISTRIB_POVERMCH_CHN;
  }

  if(!DISTRIB_ANGLE_RAD){
   	delete DISTRIB_ANGLE_RAD;
  }

  if(!DISTRIB_TLV_MET){
   	delete DISTRIB_TLV_MET;
  }
  if(!DISTRIB_P1_P2_CHN){
   	delete DISTRIB_P1_P2_CHN;
  }
  if(!DISTRIB_P1_P2_CHCH){
   	delete DISTRIB_P1_P2_CHCH;
  }
  if(!DISTRIB_PT1_PT2){
   	delete DISTRIB_PT1_PT2;
  }
  if(!DISTRIB_PT1_PT2_CHCH){
   	delete DISTRIB_PT1_PT2_CHCH;
  }
  if(!DISTRIB_PT1_PT2_CHN){
   	delete DISTRIB_PT1_PT2_CHN;
  }
  if(!DISTRIB_PT1_PT2_NN){
   	delete DISTRIB_PT1_PT2_NN;
  }
  if(!DISTRIB_MET_pt_CHCH){
   	delete DISTRIB_MET_pt_CHCH;
  }
  if(!DISTRIB_MET_pt_CHN){
   	delete DISTRIB_MET_pt_CHN;
  }
  if(!DISTRIB_MET_ptN_CHN){
   	delete DISTRIB_MET_ptN_CHN;
  }
   //delete[] passTrigger;
}


Int_t AnaEff::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

Long64_t AnaEff::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}



void AnaEff::Init(TTree *tree)
{

   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   //******************************* LIST OF ALL BRANCHES *******************************


   fChain->SetBranchAddress("ntrigger", &ntrigger, &b_ntrigger);
   fChain->SetBranchAddress("prescaleTrigger", prescaleTrigger, &b_prescaleTrigger);

   fChain->SetBranchAddress("nameTrigger", &triggerName, &b_triggerName);
   fChain->SetBranchAddress("nmuons", &nmuons, &b_nmuons);
   fChain->SetBranchAddress("passTrigger", passTrigger, &b_passTrigger); // & devant PT 1
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("npv", &npv, &b_npv);
   fChain->SetBranchAddress("ngoodpv", &ngoodpv, &b_ngoodpv);
   fChain->SetBranchAddress("track_pt", track_pt, &b_track_pt);
   fChain->SetBranchAddress("track_pterr", track_pterr, &b_track_pterr);
   fChain->SetBranchAddress("hscp_track_idx", hscp_track_idx, &b_hscp_track_idx);
   fChain->SetBranchAddress("nhscp", &nhscp, &b_nhscp);
   fChain->SetBranchAddress("ngenpart", &ngenpart, &b_ngenpart);
   fChain->SetBranchAddress("gen_status", gen_status, &b_gen_status);

   fChain->SetBranchAddress("gen_moth_pdg", gen_moth_pdg, &b_gen_moth_pdg);
   fChain->SetBranchAddress("pfmet_pt", pfmet_pt, &b_pfmet_pt);
   fChain->SetBranchAddress("track_eta", track_eta, &b_track_eta);
   fChain->SetBranchAddress("track_npixhits", track_npixhits, &b_track_npixhits);
   fChain->SetBranchAddress("track_nvalidhits", track_nvalidhits, &b_track_nvalidhits);
   fChain->SetBranchAddress("track_validfraction", track_validfraction, &b_track_validfraction);
   fChain->SetBranchAddress("ndedxhits", &ndedxhits, &b_ndedxhits);
   fChain->SetBranchAddress("track_dxy", track_dxy, &b_track_dxy);
   fChain->SetBranchAddress("track_qual", track_qual, &b_track_qual);
   fChain->SetBranchAddress("track_nhits", track_nhits, &b_track_nhits);
   fChain->SetBranchAddress("ndedxhits", &ndedxhits, &b_ndedxhits);
   fChain->SetBranchAddress("track_dz", track_dz, &b_track_dz);
   fChain->SetBranchAddress("hscp_iso2_tk", hscp_iso2_tk, &b_hscp_iso2_tk);
   fChain->SetBranchAddress("muon_isTrackerMuon", muon_isTrackerMuon, &b_muon_isTrackerMuon);
   fChain->SetBranchAddress("muon_comb_inversebeta", muon_comb_inversebeta, &b_muon_comb_inversebeta);
   fChain->SetBranchAddress("track_p", track_p, &b_track_p);
   fChain->SetBranchAddress("track_ih_ampl", track_ih_ampl, &b_track_ih_ampl);
   fChain->SetBranchAddress("track_ias_ampl", track_ias_ampl, &b_track_ias_ampl);
   fChain->SetBranchAddress("muon_phi", muon_phi, &b_muon_phi);
   fChain->SetBranchAddress("muon_eta", muon_eta, &b_muon_eta);
   fChain->SetBranchAddress("muon_pt", muon_pt, &b_muon_pt);
   
   fChain->SetBranchAddress("muon_isoR03_sumChargedHadronPt", muon_isoR03_sumChargedHadronPt, &b_muon_isoR03_sumChargedHadronPt);
   fChain->SetBranchAddress("track_phi", track_phi, &b_track_phi);
   fChain->SetBranchAddress("ntracks", &ntracks, &b_ntracks);
   fChain->SetBranchAddress("hscp_muon_idx", hscp_muon_idx, &b_hscp_muon_idx); 
   fChain->SetBranchAddress("muon_isMediumMuon", muon_isMediumMuon, &b_muon_isMediumMuon);
   fChain->SetBranchAddress("muon_p", muon_p, &b_muon_p);
   fChain->SetBranchAddress("gen_pdg", gen_pdg, &b_gen_pdg);
   fChain->SetBranchAddress("gen_pt", gen_pt, &b_gen_pt);
   fChain->SetBranchAddress("gen_eta", gen_eta, &b_gen_eta);
   fChain->SetBranchAddress("gen_phi", gen_phi, &b_gen_phi);
   fChain->SetBranchAddress("gen_mass", gen_mass, &b_gen_mass);
   Notify();
}

Bool_t AnaEff::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void AnaEff::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}

#endif
