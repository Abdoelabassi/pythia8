//Simulating LHC proton-proton collisions
//Author: EL Abassi Abderrazaq 08/09/2022

#include <iostream>
#include "Pythia8/Pythia.h"
using namespace Pythia8;
int main(){

	int events = 10;
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

		for (int j=0; j < entries;j++){
			int id = pythia.event[j].id();
			double mass = pythia.event[j].m();
			double px = pythia.event[j].px();
			double py = pythia.event[j].py();
			double pz = pythia.event[j].pz();

			double p = sqrt(pow(px,2) + pow(py,2) + pow(pz,2));

			std::cout <<  id << "mass: " << mass << "Total momentum: " << p << std::endl;
		}
	}






	return 0;
 }
