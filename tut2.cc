//Simulating LHC proton-proton collisions
//Author: EL Abassi Abderrazaq 08/09/2022

#include <iostream>
#include "Pythia8/Pythia.h"
using namespace Pythia8;
int main(){

	int events = 30;
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

		for (int j=0; j < entries;j++){
			int id = pythia.event[j].id();
			double mass = pythia.event[j].m();
			double px = pythia.event[j].px();
			double py = pythia.event[j].py();
			double pz = pythia.event[j].pz();
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




	return 0;
 }
