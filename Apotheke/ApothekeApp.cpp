#include "UI.h"
#include "Tests.h"
#include <iostream>


int main() {
	std::cout << "Testing!!\n\n";
	Tests t;
	t.allTests();
	std::cout << "Tests Over!!\n\n";
	Repository repo;
	Controller ctrl = Controller(repo);
	ApothekeUI au = ApothekeUI(ctrl);
	au.UI();
}