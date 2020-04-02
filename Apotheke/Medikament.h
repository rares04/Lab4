#pragma once
#include <string>

using namespace std;

class Medikament {
private:
	string name;
	double konzentration;
	double menge;
	double preis;

public:
	// Constructor
	Medikament(string _name, double _konzentration, double _menge, double _preis);

	// Returns the name of the medicine
	string getName() const;

	// Changes the name of the medicine
	void setName(string _name);

	// Returns the concentration of the medicine
	double getKonzentration() const;

	// Chnges the concentration of the medicine
	void setKonzentration(double _konzentration);

	// Returns the amount of this medication
	double getMenge() const;

	// Chnges the amount of this medication
	void setMenge(double _menge);

	// Returns the price of the medicine
	double getPreis() const;

	// Chnges the price of the medicine
	void setPreis(double _preis);

	// Prints details about a medicine
	string toString() const;

	// Overloading Comparsion Operators
	friend bool operator == (const Medikament& m1, const Medikament& m2);
	friend bool operator != (const Medikament& m1, const Medikament& m2);
};