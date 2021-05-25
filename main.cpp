#include <iostream>
#include "parse.hpp"
#include "print.hpp"


using namespace std;

int main(int argc, char** argv){
	Factory* factory_pattern = new Parse();
	Base* test = factory->parse(argc, argv);
	
	if (test) {
		cout << test->stringify() << " = " << test->evaluate() << endl;
		cout << "Latex: \n" << print_latex(test) << endl;
		cout << "MathML: \n" << print_mathML(test) << enl;
	} else {
		cout << "Error: Invalid" << endl;
	}

	delete factory_pattern;
	delete test;	

	return 0;
}
