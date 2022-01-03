********************** Raphael Haberle **********************
********************** rhaeberl@iphc.cnrs.fr ****************



Step 1 : You need a .root containing the ntuple of your choice (no other format is accepted in this script)

[ Example : I have a 70 Gb file at > /opt/sbg/cms/ui2_data1/rhaeberl/CMSSW_10_6_2/src/HSCPtriggerStudies/all_gluino2000.root ]

Step 2 : - In Skelet.h replace lines 341 / 337 / 334 with the path to your .root file
	 

Step 3 : In skelet.cpp  > change line 26 for the mass of your simulated events
			  change line 350 for the type of particles simulated
			  change line 352 for the scenario you want to study
			  
			  


Then you can upload your file where your environment is set, and run the following commands :

./compilemain.sh
time ./bin/Skelet <scenario>

The study starts now, you can monitor your progress bar in the terminal

Once it is terminated, the code will output many different things depending on what were the inputs :
The scenario 

