#pragma once
#include <vector>
#include "Medikament.h"
#include <utility>


class Repository {
private:
    std::vector <Medikament> medikamente;
    std::string lastOperation = "";
    std::string lastUndo = "";
    Medikament lastMedicament = Medikament("",0,0,0);
    Medikament newMedicament = Medikament("",0,0,0);
public:
    // Adds a medicine to the medicine list
    void add_medikament(Medikament medikament);

    // Deletes a medicine from the medicine list
    void delete_medikament(Medikament medikament);

    // Edits a medicine from the medicine list
    void edit_medikament(Medikament medikament, Medikament newMedikament);

    // Undo's the last operation
    void undo();

    // Redo's the last operation
    void redo();

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