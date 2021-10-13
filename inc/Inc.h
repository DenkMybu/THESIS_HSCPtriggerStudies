#ifndef INC_H
#define INC_H

#include <vector>
#include <iostream>
#include <string>
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TFile.h>
#include <map>
#include <TEfficiency.h>

/*
How to compile this file : if using root : .L AnaEff.cpp 




*/

using namespace std; // ici std::vector 



class TrigEff 
{
public:
   

   TrigEff(); 
   ~TrigEff();
   

   void LoadNoMap(const vector<string> &triggerNames,const vector<string> &SelectedTriggerNames,int ErrorType=1, string NameVar="a",string FileName="testnewdata.root");


   void FillNoMap2(vector< pair<int, bool > > PosPass, float Obs = 0.0, double weight = 1,string mode = "all");


   void Compute(string NameOutputFile, string NameListEff, string ListAllTriggers, string EffTriggers, string ErrorEffTriggers,string EffOrAllTriggers);
   
   //void CreateHisto(string NameVar="random", const vector<string> &SelectedTriggerNames);

   void WritePlots(string NameVar="a",string NameOfFile="a.root"); // format latex TFile* OutputHisto

   void FillMass(double INVMASS,int choice= 1);

   void FindTurnOn(int which, bool trig1, bool trig2, float Obs, bool munomu);

   void NameTEff();

   void InitTEff();

 private :
	
//*************************************METHODS********************************************
   

   // ****************** Correlation between triggers ******************
   void ComputeCorr(); //Computes the 2D array of correlations

   void PrintCorr(); // Shows the 2D array of correlations
   
   void PrintNumCorr(); // Shows the numerator (# candidates that passed either one of the other trigger)

   void PrintDenomCorr(); // Show the denominator (# candidates that passed both triggers)

   void Get2DPlot(); // 
   


   // ************** TURN ON OF TRIGGERS *********************
  


   // ************** LOGICAL OR OF TRIGGERS *********************
   void ComputeLogicalOr();

   void PrintLogicalOr();

   // ************** Efficiency of triggers ***********************

   void ComputeEff(); // Computes the efficiency for every given trigger 
   
   void PrintEff(); //Show all efficiencies 

   void PrintNumEff(); // Show the numerator (# candidates that passed the trigger)

   void PrintDenomEff(); // Show the denominator (# candidates)
	
   void ComputeError(); // computes the error on the efficiencies

   void ComputeErrorLogicalOr();

   void ComputeCorAll();

   // ******************* Plotting ********************************

   void SavePlots(); // en png/hist ou whatever

   void SaveIntTrigs(string NameOutputFile, string NameListEff, string ListAllTriggers, string EffTriggers,string ErrorEffTriggers,string EffOrAllTriggers); // Saves the list of interesting triggers (efficiency > threshold)

   void StudyTrigvsMass(double mass); 


// ******************************FITS**************************



// ******************************MEMBERS**************************
   TFile* OutputHisto;

   vector <TEfficiency*> EffvsObs;
   vector <TEfficiency*> EffvsObsNo;

  
   
};

#endif
