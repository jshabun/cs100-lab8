#ifndef __PRINT_HPP__
#define __PRINT_HPP__

#include "visitorLATEX.hpp"
#include "visitmathml.hpp"
#include "iterator.hpp"
#include <string>

using namespace std;

string print_latex(Base* ptr) {
	VisitorLaTeX* visit = new VisitorLaTeX();
	Iterator iter(ptr);
	
	while(!iter.is_done()) {
		iter.current_node()->accept(visit, iter.current_index());
		iter.next();
	}
	
	string result;
	result += "$" + visit->getString() + "$";
	delete visit;
	return result;
}

string print_mathML(Base* ptr) {
	VisitMathMl* visit = new VisitMathMl();
	Iterator iter(ptr);
	
	while(!iter.is_done()) {
		iter.current_node()->accept(visit, iter.current_index());
		iter.next();
	}

	string result;
	result += "<math>\n" + visit->getString() + "</math>";
	delete visit;
	return result;
}

#endif // __PRINT_HPP__
