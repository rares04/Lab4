#include "Repository.h"
#include <algorithm>
using namespace std;

void Repository::add_medikament(Medikament _medikament) {
	bool found = false;
	for (std::size_t i = 0; i < medikamente.size(); ++i)
		if (medikamente[i] == _medikament) {
			medikamente[i].setMenge(medikamente[i].getMenge() + _medikament.getMenge());
			found = true;
			break;
		}
	if (found == false)
		medikamente.push_back(_medikament);
}

void Repository::delete_medikament(Medikament _medikament) {
    for(int i = 0; i < medikamente.size(); ++i) {
        if (medikamente[i] == _medikament) {
            medikamente.erase(medikamente.begin()+i);
        }
    }
}

void Repository::edit_medikament(Medikament _medikament,string name, double konz, double meng, double preis) {
    for (std::size_t i = 0; i < medikamente.size(); ++i)
        if (medikamente[i] == _medikament) {
            medikamente[i].setName(name);
            medikamente[i].setKonzentration(konz);
            medikamente[i].setMenge(meng);
            medikamente[i].setPreis(preis);
        }
}


std::vector<Medikament> Repository::getMedikamente() const {
	return this->medikamente;
}


Medikament Repository::getMedikament_byIndex(int index) const {
	return this->medikamente[index];
}


double Repository::getSize() const {
	return this->medikamente.size();
}


bool compareName(Medikament m1, Medikament m2) {
	return m1.getName() < m2.getName();
}


void Repository::sortByName() {
	sort(medikamente.begin(), medikamente.end(), compareName);
}


bool comparePreis(Medikament m1, Medikament m2) {
	return m1.getPreis() < m2.getPreis();
}


void Repository::sortByPrice() {
	sort(medikamente.begin(), medikamente.end(), comparePreis);
}
