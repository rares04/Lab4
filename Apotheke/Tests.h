#pragma once
#include "Repository.h"


class Tests {
private:
    Medikament m1 = Medikament("SORTIS", 20, 1, 16.66);
    Medikament m2 = Medikament("ROSUCARD", 10, 3, 16.66);
    Medikament m3 = Medikament("SORTIS", 40, 5, 15.54);
    Medikament m4 = Medikament("ROSUVASTATINA TERAPIA", 10, 2, 15.54);
    Medikament m5 = Medikament("SORTIS", 20, 10, 16.66);
    Medikament m6 = Medikament("ACID ALENDRONIC AUROBINDO", 70, 5, 10.48);
    Medikament m7 = Medikament("ZEPLAN(R)", 40, 2, 10.36);
    Medikament m8 = Medikament("PRAVATOR", 20, 5, 5.04);
    Medikament m9 = Medikament("PRAVATOR", 40, 5, 10.36);
    Medikament m10 = Medikament("PRAVATOR", 20, 7, 5.04);

public:
    void testAdd() const;
    void testDelete() const;
    void testEdit() const;
    void testUndo() const;
    void testRedo() const;
    void testKnapp() const;
    void testStrFind() const;
    void testGroupPrice() const;
    void allTests() const;
};