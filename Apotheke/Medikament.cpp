#include "Medikament.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


Medikament::Medikament(string _name, double _konzentration, double _menge, double _preis) {
	name = _name;
	konzentration = _konzentration;
	menge = _menge;
	preis = _preis;
}


string Medikament::getName() const {
	return this->name;
}


void Medikament::setName(string _name) {
	this->name = _name;
}


double Medikament::getKonzentration() const {
	return this->konzentration;
}


void Medikament::setKonzentration(double _konzentration) {
	this->konzentration = _konzentration;
}


double Medikament::getMenge() const {
	return this->menge;
}


void Medikament::setMenge(double _menge) {
	this->menge = _menge;
}


double Medikament::getPreis() const {
	return this->preis;
}


void Medikament::setPreis(double _preis) {
	this->preis = _preis;
}


string Medikament::toString() const {
	stringstream out;
	out << "Medikament \n\tName: " << this->getName()<< endl << "\tKonzentration: " << this->getKonzentration() << endl << "\tMenge: " << this->getMenge() << endl << "\tPreis: " << this->getPreis() << endl << endl;
	return out.str();
}


bool operator == (const Medikament& m1, const Medikament& m2) {
	return (m1.getName() == m2.getName() && m1.getKonzentration() == m2.getKonzentration());
}

bool operator != (const Medikament& m1, const Medikament& m2) {
	return !(m1 == m2);
}