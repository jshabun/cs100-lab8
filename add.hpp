#ifndef __ADD_HPP__
#define __ADD_HPP__

#include <iostream>
#include <string>

#include "op.hpp"
#include "visitor.hpp"

using namespace std;

class Add: public Base {
   public:
	Add(Base* add1, Base* add2) : Base() {
		this->add1 = add1;
	  	this->add2 = add2;
	}

	virtual double evaluate() {
		 return (add1->evaluate() + add2->evaluate());
	}

	virtual std::string stringify() {
		 return ("(" + add1->stringify() + " + " + add2->stringify() + ")");
	}

	virtual int number_of_children() {return 2;}
	virtual Base* get_child(int i) {
			if(i == 0)
					return add1;
			if(i == 1) 
					return add2;
	}

	virtual void accept(Visitor* visitor, int index) {
			if (index == 0)
					visitor->visit_add_begin(this);
			else if (index == 1)
					visitor->visit_add_middle(this);
			else if (index == 2)
					visitor->visit_add_end(this);
	}

   private:
	Base* add1;
	Base* add2;
};

#endif //__ADD_HPP__
