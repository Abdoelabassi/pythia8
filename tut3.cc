//Simulating LHC proton-proton collisions
//Author: EL Abassi Abderrazaq 08/09/2022
//C++
#include <iostream>
//ROOT
#include "TFile.h"
#include "TTree.h"
//Pythia
#include "Pythia8/Pythia.h"
using namespace Pythia8;
int main(){

	TFile *output = new TFile("tut3.root","recreate");
	TTree *tree =  new TTree("tree","tree");
	
	//vars to store in the ttree
	int id, event, size, pn;
	double mass, px, py, pz;
	
	tree->Branch("id",&id,"id/I");
	tree->Branch("event",&event, "event/I");
	tree->Branch("size",&size, "size/I");
	tree->Branch("nop",&pn, "nop/I");
	tree->Branch("mass",&mass, "mass/D");
	tree->Branch("px",&px,"px/D");
	tree->Branch("py",&py,"py/D");
	tree->Branch("pz",&pz,"pz/D");

	int events = 1e4;
	Pythia pythia;
	pythia.readString("Beams:idA=2212");
	pythia.readString("Beams:idB=2212");
	pythia.readString("Beams:eCM=14.e3");
	pythia.readString("SoftQCD:all= on");
	pythia.readString("HardQCD:all= on");
	pythia.init();
	Hist hpz("Momementum Distribution in z direction",100,-10,10);
	Hist hmass("Mass Distribution",50,0,5);

	for (int i=0; i < events;i++){
		if(!pythia.next()) continue;
		int entries = pythia.event.size();
		std::cout << "Event: " << i << std::endl;
		std::cout << "Event size: " << entries << std::endl;
		event = i;
		size= entries;

		for (int j=0; j < entries;j++){
			id = pythia.event[j].id();
			pn=j;
			double mass = pythia.event[j].m();
			double px = pythia.event[j].px();
			double py = pythia.event[j].py();
			double pz = pythia.event[j].pz();
			tree->Fill();
			hpz.fill(pz);
			hmass.fill(mass);

			double p = sqrt(pow(px,2) + pow(py,2) + pow(pz,2));

			std::cout << "id : " <<  id << " mass: " << mass << " Total momentum: " << p << std::endl;
	 	}
	}

	 std::cout << hpz << std::endl;
	 std::cout << hmass << std::endl;

	 HistPlot hpl("tut2");
	 HistPlot hpp ("tut2-2");
    	 hpl.frame("pz", "Momentum Distribution", "Momentum", "Entries");
	 hpp.frame("mass","Mass Distribution","Mass","Entries");
    	 hpl.add(hpz);
	 hpp.add(hmass);
    	 hpl.plot();
	 hpp.plot();
	 
	 output->Write();
	 output->Close();




	return 0;
 }
