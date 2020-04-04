#pragma once
#include <vector>
#include "Medikament.h"


class Repository {
private:
	std::vector <Medikament> medikamente;
public:
	// Add a medicine to the medicine list
	void add_medikament(Medikament medikament);

    // Deletes a medicine from the medicine list
    void delete_medikament(Medikament medikament);

    // Edits a medicine from the medicine list
    void edit_medikament(Medikament medikament, string name, double konz, double meng, double preis);


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