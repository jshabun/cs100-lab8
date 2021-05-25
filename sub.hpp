#ifndef __SUB_HPP__
#define __SUB_HPP__

#include <iostream>
#include <string>

#include "op.hpp"
#include "visitor.hpp"

using namespace std;

class Sub: public Base {
   public:
	Sub(Base* sub1, Base* sub2) : Base() {
		this->sub1 = sub1;
		this->sub2 = sub2;
	}
	
	virtual double evaluate() {
		return (sub1->evaluate() - sub2->evaluate());
	}

	virtual std:: string stringify() {
		return ("(" + sub1->stringify() + " - " + sub2->stringify() + ")");
	}

	virtual int number_of_children() {return 2;}
	virtual Base* get_child(int i) {
			if (i == 0)
				return sub1;
			if (i == 1)
				return sub2;
	}
	
	virtual void accept(Visitor* visit, int index) {
				if (index == 0)
				visit->visit_sub_begin(this);
			else if (index == 1)
				visit->visit_sub_middle(this);
			else if (index == 2)
				visit->visit_sub_end(this);
	}

   private:
	Base* sub1;
	Base* sub2;
};

#endif //__SUB_HPP__
