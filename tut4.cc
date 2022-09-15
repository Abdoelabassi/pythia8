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
	double mass, px, py, pz, p;

	tree->Branch("id",&id,"id/I");
	tree->Branch("event",&event, "event/I");
	tree->Branch("size",&size, "size/I");
	tree->Branch("nop",&pn, "nop/I");
	tree->Branch("mass",&mass, "mass/D");
	tree->Branch("px",&px,"px/D");
	tree->Branch("py",&py,"py/D");
	tree->Branch("pz",&pz,"pz/D");
	tree->Branch("p",&p,"p/D");

	int events = 1e4;
	Pythia pythia;
	pythia.readString("Beams:idA=2212");
	pythia.readString("Beams:idB=2212");
	pythia.readString("Beams:eCM=14.e3");
	pythia.readString("SoftQCD:all= on");
	pythia.readString("HardQCD:all= on");
	pythia.init();
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
			mass = pythia.event[j].m();
			px = pythia.event[j].px();
			py = pythia.event[j].py();
			pz = pythia.event[j].pz();
			p = sqrt(pow(px,2) + pow(py,2) + pow(pz,2));
			tree->Fill();

			std::cout << "id : " <<  id << " mass: " << mass << " Total momentum: " << p << std::endl;
	 	}
	}

	 output->Write();
	 output->Close();




	return 0;
 }
