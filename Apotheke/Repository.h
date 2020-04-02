#pragma once
#include <vector>
#include "Medikament.h"


class Repository {
private:
	std::vector <Medikament> medikamente;
public:
	// Add a medicine to the medicine list
	void add_medikament(Medikament medikament);

	// Returns the list with medicines
	std::vector<Medikament> getMedikamente() const;

	// Returns a medicine from a given index
	Medikament getMedikament_byIndex(int index) const;

	// Returns the size of the vector
	double getSize() const;
	
	// Sorts the medications after name lexicographically
	void sortByName();

	// Sorts the medications after price
	void sortByPrice();
};