#include "UI.h"
#include <iostream>

using namespace std;


ApothekeUI::ApothekeUI(Controller _ctrl) : ctrl(_ctrl){
}


void Infos() {
	// Infos uber die mogliche Operationen

	cout << "\n\n";
	cout << "0. Fur Exit\n";
	cout << "1. Fur Einfugen Medikament\n";
	cout << "2. Fur Loschen Medikament\n";
	cout << "3. Fur Edit Medikament\n";
	cout << "4. Fur Suchen Mediakment containing given string\n";
	cout << "5. Fur Suchen Medikamente die die Menge weniger als gegebenen Wert haben\n";
	cout << "6. Fur Group Medikamente nach preis\n";
	cout << "7. Fur UNDO letzte Operation\n";
	cout << "8. Fur REDO letzte Operation\n";
}


void ApothekeUI::UI() {
	// Es gibt 9 mogliche Operationen, also 9 if statements, in jeder if statement wird eine Operation gemacht

	Infos();
	int input;
	string name, new_name, zeichen;
	double konzentration, menge, preis, new_konzentration, new_menge, new_preis;
	cout << "\nInput: "; cin >> input;
	while (input != 0) {
		if (input == 1) {
			cout << "Um ein Medikmanet hinzufugen, mussen sie Name, Konzentration, Menge und Preis des Medikamentes schreiben:\n";
			cout << "Name: "; cin >> name;
			cout << "Konzentration: "; cin >> konzentration;
			cout << "Menge: "; cin >> menge;
			cout << "Preis: "; cin >> preis;
			Medikament med = Medikament(name, konzentration, menge, preis);
			ctrl.repo.add_medikament(med);
		}
		else if (input == 2) {
			cout << "Um ein Medikmanet zu loschen, mussen sie Name, Konzentration, Menge und Preis des Medikamentes schreiben:\n";
			cout << "Name: "; cin >> name;
			cout << "Konzentration: "; cin >> konzentration;
			cout << "Menge: "; cin >> menge;
			cout << "Preis: "; cin >> preis;
			Medikament med = Medikament(name, konzentration, menge, preis);
			ctrl.repo.delete_medikament(med);
		}
		else if (input == 3) {
			cout << "Um ein Medikmanet zu verandern, mussen sie die Daten uber den alten Medikament geben und die Daten uber den neuen Medikament\n";
			cout << "Name: "; cin >> name;
			cout << "Konzentration: "; cin >> konzentration;
			cout << "Menge: "; cin >> menge;
			cout << "Preis: "; cin >> preis;
			cout << "new_Name: "; cin >> new_name;
			cout << "new_Konzentration: "; cin >> new_konzentration;
			cout << "new_Menge: "; cin >> new_menge;
			cout << "new_Preis: "; cin >> new_preis;
			Medikament med = Medikament(name, konzentration, menge, preis);
			Medikament med2 = Medikament(new_name, new_konzentration, new_menge, new_preis);
			ctrl.repo.edit_medikament(med, med2);
		}
		else if (input == 4) {
			cout << "Um alle verfugbare Medkimante die einen Zeichenstring enthalten zu sehen (sortiert nach Name) mussen sie den Zeichenstring geben:";
			cout << "\nZeichen: "; cin >> zeichen;
			ctrl.strFind(zeichen);
		}
		else if (input == 5) {
			cout << "Um nur die Medikament, die die Menge weniger als X haben zu sehen, geben sie den Wert von X:\n";
			double X;
			cout << "X: "; cin >> X;
			ctrl.knapp(X);
		}
		else if (input == 6) {
			cout << "Sie werden die Medikamente nach Preis gruppiert sehen\n";
			ctrl.groupPrice();
		}
		else if (input == 7) {
			cout << "UNDO fur die letze Operation wird gemacht\n";
			ctrl.repo.undo();
		}
		else if (input == 8) {
			cout << "REDO fur die letze Operation wird gemacht\n";
			ctrl.repo.redo();
		}
		else if (input == 0)
			exit(0);
		else cout << "wrong input\n";

		Infos();
		cout << "\nInput: "; cin >> input;
	}
}