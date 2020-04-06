#include "Tests.h"
#include "Controller.h"
#include <cassert>



void Tests::testAdd() const {
    Repository  r;
    r.add_medikament(m1);
    r.add_medikament(m2);
    r.add_medikament(m3);
    r.add_medikament(m4);
    r.add_medikament(m5);
    r.add_medikament(m6);
    r.add_medikament(m7);
    r.add_medikament(m8);
    r.add_medikament(m9);
    r.add_medikament(m10);

    // Diese sind die Medikamente die gleich sind, und nur die Menge sollte grosser sein
    assert(r.getMedikament_byIndex(0).getMenge() == 11);   // SORTIS 20 mg
    assert(r.getMedikament_byIndex(6).getMenge() == 12);   // PRAVATOR 20 mg
}


void Tests::testDelete() const{
    Repository r;
    r.add_medikament(m1);
    r.add_medikament(m2);
    r.add_medikament(m2);
    assert(r.getSize() == 2);
    r.delete_medikament(m1);
    assert(r.getSize() == 1);
    assert(r.getMedikament_byIndex(0).getMenge() == 6);
    r.delete_medikament(m2);
    assert(r.getMedikament_byIndex(0).getMenge() == 3);
}

void Tests::testEdit()  const{
    Repository r;
    Medikament med2 = Medikament("PROPOLIS", 20, 5, 14.02);
    r.add_medikament(m1);
    assert(r.getMedikament_byIndex(0).getName() == "SORTIS");
    assert(r.getMedikament_byIndex(0).getKonzentration() == 20);
    assert(r.getMedikament_byIndex(0).getMenge() == 1);
    assert(r.getMedikament_byIndex(0).getPreis() == 16.66);
    r.edit_medikament(m1, med2);
    assert(r.getMedikament_byIndex(0).getName() == "PROPOLIS");
    assert(r.getMedikament_byIndex(0).getKonzentration() == 20);
    assert(r.getMedikament_byIndex(0).getMenge() == 5);
    assert(r.getMedikament_byIndex(0).getPreis() == 14.02);

}

void Tests::testUndo() const {
    Repository r;
    Medikament med2 = Medikament("PROPOLIS", 20, 5, 14.02);
    r.add_medikament(m1);
    assert(r.getSize() == 1);
    r.undo();
    assert(r.getSize() == 0);

    r.add_medikament(m1);
    r.delete_medikament(m1);
    assert(r.getSize() == 0);
    r.undo();
    assert(r.getSize() == 1);

    r.edit_medikament(m1, med2);
    assert(r.getMedikament_byIndex(0).getName() == "PROPOLIS");
    assert(r.getMedikament_byIndex(0).getKonzentration() == 20);
    assert(r.getMedikament_byIndex(0).getMenge() == 5);
    assert(r.getMedikament_byIndex(0).getPreis() == 14.02);
    r.undo();
    assert(r.getMedikament_byIndex(0).getName() == "SORTIS");
    assert(r.getMedikament_byIndex(0).getKonzentration() == 20);
    assert(r.getMedikament_byIndex(0).getMenge() == 1);
    assert(r.getMedikament_byIndex(0).getPreis() == 16.66);
}

void Tests:: testRedo() const {
    Repository r;
    Medikament med2 = Medikament("PROPOLIS", 20, 5, 14.02);
    r.add_medikament(m1);
    assert(r.getSize() == 1);
    r.undo();
    assert(r.getSize() == 0);
    r.redo();
    assert(r.getSize() == 1);

    r.delete_medikament(m1);
    assert(r.getSize() == 0);
    r.undo();
    assert(r.getSize() == 1);
    r.redo();
    assert(r.getSize() == 0);

    r.add_medikament(m1);
    r.edit_medikament(m1, med2);
    assert(r.getMedikament_byIndex(0).getName() == "PROPOLIS");
    assert(r.getMedikament_byIndex(0).getKonzentration() == 20);
    assert(r.getMedikament_byIndex(0).getMenge() == 5);
    assert(r.getMedikament_byIndex(0).getPreis() == 14.02);
    r.undo();
    assert(r.getMedikament_byIndex(0).getName() == "SORTIS");
    assert(r.getMedikament_byIndex(0).getKonzentration() == 20);
    assert(r.getMedikament_byIndex(0).getMenge() == 1);
    assert(r.getMedikament_byIndex(0).getPreis() == 16.66);
    r.redo();
    assert(r.getMedikament_byIndex(0).getName() == "PROPOLIS");
    assert(r.getMedikament_byIndex(0).getKonzentration() == 20);
    assert(r.getMedikament_byIndex(0).getMenge() == 5);
    assert(r.getMedikament_byIndex(0).getPreis() == 14.02);
}

void Tests::testKnapp() const {
    Repository  r;
    r.add_medikament(m1);
    r.add_medikament(m2);
    r.add_medikament(m3);
    r.add_medikament(m4);
    r.add_medikament(m5);
    r.add_medikament(m6);
    r.add_medikament(m7);
    r.add_medikament(m8);
    r.add_medikament(m9);
    r.add_medikament(m10);

    Controller c = Controller(r);
    c.knapp(7);
}


void Tests::testStrFind() const {
    Repository  r;
    r.add_medikament(m1);
    r.add_medikament(m2);
    r.add_medikament(m3);
    r.add_medikament(m4);
    r.add_medikament(m5);
    r.add_medikament(m6);
    r.add_medikament(m7);
    r.add_medikament(m8);
    r.add_medikament(m9);
    r.add_medikament(m10);

    Controller c = Controller(r);
    c.strFind("");
    c.strFind("ORTI");
}


void Tests::testGroupPrice() const {
    Repository  r;
    r.add_medikament(m1);
    r.add_medikament(m2);
    r.add_medikament(m3);
    r.add_medikament(m4);
    r.add_medikament(m5);
    r.add_medikament(m6);
    r.add_medikament(m7);
    r.add_medikament(m8);
    r.add_medikament(m9);
    r.add_medikament(m10);

    Controller c = Controller(r);
    c.groupPrice();
}


void Tests::allTests() const {
    Tests t;
    t.testAdd();
    t.testDelete();
    t.testEdit();
    t.testUndo();
    t.testRedo();
    t.testKnapp();
    t.testStrFind();
    t.testGroupPrice();
}