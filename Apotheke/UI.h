#pragma once
#include "Controller.h"


class ApothekeUI {
private:
	Controller ctrl;
public:
	// Constructotr
	ApothekeUI(Controller _ctrl);

	// Function with user input
	void UI();
};