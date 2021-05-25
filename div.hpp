#ifndef __DIV_HPP__
#define __DIV_HPP__

#include <iostream>
#include <string>
#include "op.hpp"
#include "visitor.hpp"

using namespace std;

class Div: public Base {
   public:
	Div(Base* div1, Base* div2) : Base() {
		this->div1 = div1;
		this->div2 = div2;
	}

	virtual double evaluate() {
		return (div1->evaluate() / div2->evaluate());
	}

	virtual std::string stringify() {
		return("(" + div1->stringify() + " / " + div2->stringify() + ")");
	}

	virtual int number_of_children() {return 2;}
	virtual Base* get_child(int i) {
		if (i == 0)
			return this->lhs;
		if (i == 1)
			return this->rhs;
	}

	virtual void accept(Visitor* visitor, int index) {
		if (index == 0)
			visitor->visit_div_begin(this);
		else if (index == 1)
			visitor->visit_div_middle(this);
		else if (index == 2)
			visitor->visit_div_end(this);
	}

   private:
	Base* div1;
	Base* div2;
};

#endif //__DIV_HPP__
