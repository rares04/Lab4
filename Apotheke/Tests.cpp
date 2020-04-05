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


int main() {
	Tests t;
	t.testAdd();
	t.testKnapp();
	t.testStrFind();
	t.testGroupPrice();
}