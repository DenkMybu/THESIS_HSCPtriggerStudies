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

	
	DISTRIB_NB_RHADRONS = new TH1D ("DISTRIB_NB_RHADRONS" , " ( nb r hadrons (all scenarios) )", 6,0,4);
	DISTRIB_NB_RHADRONS->GetXaxis()->SetTitle("# R-hadrons");
	DISTRIB_NB_RHADRONS->GetYaxis()->SetTitle("# events");



	
	
	DISTRIB_NB_RHADRONS->Sumw2();

	//trigEff_presel.LoadNoMap(triggerNames,triggerNames,1,DataType,NameOfFile);
	
	//trigEff_selection_obs.LoadNoMap(triggerNames,triggerNames,1,DataType,NameOfFile);  // call a function from other class .h
	

	cout << "Before loop nentries" << endl;
	for (Long64_t jentry=0; jentry<nentries;jentry++) { //All entries
		Long64_t ientry = LoadTree(jentry);
		if(jentry!=0 && jentry%1000==0) cout << "+1k" << " => " << jentry << " , "<<(jentry*1.0/nentries)*100 << " %" << endl;
		if (ientry < 0) break;
        	nb = fChain->GetEntry(jentry);   nbytes += nb;	
	
		
	}


	DISTRIB_NB_RHADRONS->Write();

	cout << "After loop nentries" << endl;
	
	cout << "Program terminated without any logic call out of bound" << endl;

}

void AnaEff::AssoGenId(int indexcandidate){

	vector<int> indexpdgch{1009213, 1009323, 1092214, 1091114, 1093114, 1093224, 1093314, 1093334, 1000612, 1000632, 1000652, 1006211, 1006213, 1006313, 1006321, 1006323 };
	vector<int> indexpdgn{1000622, 1093324, 1092114, 1000993, 1009113, 1009223, 1009313, 1009333, 1093214, 1000642, 1006113, 1006311, 1006313};
	vector<int> indexpdgch2{1006223, 1092224};

	vector<int> candidatesrh,candidatesneutral,candidatesdoublech;
	int nbmothgen=0;
	int nbnn=0;
	double p1=0,p2=0,eta1=0,eta2=0,pt1=0,pt2=0;
	float poverm1,poverm2;
	//cout << " NEW EVENT ------"<<endl;
	for(int i=0; i < ngenpart ; i++){
		
		//cout << "gen : " << gen_pdg[i] << " , gen_moth : " << gen_moth_pdg[i] << " , status : " << gen_status[i] << " , p = pt * cosh(eta) : " << gen_pt[i] * cosh(gen_eta[i]) << endl;


		if(gen_moth_pdg[i] == 1000021){
			nbmothgen+=1;
		}

		for(int k = 0; k < indexpdgch.size() ; k++){
			if(abs(gen_pdg[i]) == indexpdgch[k]){
				if(gen_status[i] == 1){
					nbch+=1;
					candidatesrh.push_back(i);
				}
			}
		}
		
		for(int j=0; j < indexpdgn.size(); j++){
			if(abs(gen_pdg[i]) == indexpdgn[j]){
				if(gen_status[i] == 1){
				 nbn+=1;
				 candidatesneutral.push_back(i);
				}
			}
		}
		
		
		for(int j=0; j < indexpdgch2.size(); j++){
			if(abs(gen_pdg[i]) == indexpdgch2[j]){
				if(gen_status[i] == 1){
					candidatesdoublech.push_back(i);
					cout << "gen : " << gen_pdg[i] << " , gen_moth : " << gen_moth_pdg[i] << " , status : " << gen_status[i] << " , p = pt * cosh(eta) : " << gen_pt[i] * cosh(gen_eta[i]) << endl;
				}
			}
		}
	}
	DISTRIB_NB_RHADRONS->Fill(candidatesrh.size() + candidatesneutral.size() + candidatesdoublech.size());
	cout << " Number of HSCP (charged + neutral + double charged) " << candidatesrh.size() + candidatesneutral.size() + candidatesdoublech.size() << endl;
	bool alo = false,alo2=false;


	nbtot+=1;
	//cout << "nb neutral : " << candidatesneutral.size() << " , nb charged : " << candidatesrh.size() << " ,nb tot = " << candidatesneutral.size() + candidatesrh.size() <<endl;
	if(candidatesdoublech.size() >= 1 ){
		nbtch+=1;
		double deltatranfrdch = deltaR2(track_eta[hscp_track_idx[indexcandidate]], track_phi[hscp_track_idx[indexcandidate]], gen_eta[candidatesdoublech[candidatesdoublech.size()-1]], gen_phi[candidatesdoublech[candidatesdoublech.size()-1]]);
		double finaldeltadch = deltaR(deltatranfrdch);	

		if(finaldeltadch < 0.3 ){
	
			DISTRIB_IHDCH->Fill(track_ih_ampl[hscp_track_idx[indexcandidate]]);
			DISTRIB_IASDCH->Fill(track_ias_ampl[hscp_track_idx[indexcandidate]]);
			DISTRIB_ETA_DCH->Fill(track_eta[hscp_track_idx[indexcandidate]]);
		}

		


		if(candidatesrh.size() >= 1){
			//cout << " There is " << candidatesdoublech.size() << " double charged and " << candidatesrh.size() <<" single charged " << endl;
		}
		else if(candidatesneutral.size() >= 1){
			//cout << " There is 1 double charged and 1 neutral" << endl;

		}

		else{

			//cout << " There is 1 double charged and nothing else" << endl;
		}

	}



	if( candidatesrh.size() == 0 && candidatesneutral.size() >= 1 ){
		nbnn+=1;

	}

	if( candidatesrh.size() >= 1 && candidatesneutral.size() >= 1 ){
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
				DISTRIB_MET_pt_CHN->Fill(pfmet_pt[0], gen_pt[candidatesrh[candidatesrh.size()-1]]);
			}
			else{
				DISTRIB_MET_pt_CHN->Fill(pfmet_pt[0], gen_pt[candidatesrh[candidatesneutral.size()-1]]);
			
			}

		}
		/*else if ( finaldelta1chn < 0.3 && finaldelta2chn > 0.3){
			
		}
		else if( finaldelta1chn > 0.3 && finaldelta2chn < 0.3){
			
		}
		else if( finaldelta1chn > 0.3 && finaldelta2chn > 0.3){
			
		}*/


		DISTRIB_PT1_PT2->Fill(gen_pt[candidatesrh[candidatesrh.size()-1]],gen_pt[candidatesrh[candidatesneutral.size()-1]]);
		
		

	}


	else if(candidatesrh.size() >= 2 && candidatesneutral.size() == 0){
		//cout << "charged + charged " << endl;
		double p1chch = (gen_pt[candidatesrh[candidatesrh.size()-1]] * cosh(gen_eta[candidatesrh[candidatesrh.size()-1]]));
		double p2chch = (gen_pt[candidatesrh[candidatesrh.size()-2]] * cosh(gen_eta[candidatesrh[candidatesrh.size()-2]]));
		DISTRIB_MET_CHCH->Fill(pfmet_pt[0]);
		DISTRIB_P1MP2CHCH->Fill((2*(p1chch-p2chch))/(p1chch+p2chch));

		DISTRIB_PT1_PT2->Fill(gen_pt[candidatesrh[candidatesrh.size()-1]],gen_pt[candidatesrh[candidatesrh.size()-2]]);
		DISTRIB_P1_P2_CHCH->Fill(p1chch,p2chch);
		
		
		nbchch+=1;
		double deltatranfr1 = deltaR2(track_eta[hscp_track_idx[indexcandidate]], track_phi[hscp_track_idx[indexcandidate]], gen_eta[candidatesrh[candidatesrh.size()-1]], gen_phi[candidatesrh[candidatesrh.size()-1]]);
		double finaldelta1 = deltaR(deltatranfr1);

		double deltatranfr2 = deltaR2(track_eta[hscp_track_idx[indexcandidate]], track_phi[hscp_track_idx[indexcandidate]], gen_eta[candidatesrh[candidatesrh.size()-2]], gen_phi[candidatesrh[candidatesrh.size()-2]]);
		double finaldelta2 = deltaR(deltatranfr2);			

		poverm1 = ((gen_pt[candidatesrh[candidatesrh.size()-1]] * cosh(gen_eta[candidatesrh[candidatesrh.size()-1]]))/TheorMass);
		poverm2 = ((gen_pt[candidatesrh[candidatesrh.size()-2]] * cosh(gen_eta[candidatesrh[candidatesrh.size()-2]]))/TheorMass);

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
		/*else if ( finaldelta1 < 0.3 && finaldelta2 > 0.3){
			Psurm1 = poverm1;
		}
		else if( finaldelta1 > 0.3 && finaldelta2 < 0.3){
			Psurm1 = poverm2;
		}
		else if( finaldelta1 > 0.3 && finaldelta2 > 0.3){
			Psurm1 = 0;
		}*/

	}
	
	if(alo==false && alo2 == false){
		//cout << "no track matched any gluino" << endl;
	}
	candidatesrh.clear();
	candidatesneutral.clear();
	candidatesdoublech.clear();
}


int main(){

	AnaEff ana;
	ana.Loop();
	
}
