#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "op.hpp"
#include "visitor.hpp"

using namespace std;

class Mult : public Base {
     private:
	Base* x;
	Base* y;
     public:
	Mult(Base* x, Base* y) : Base() {
	this->x = x;
	this->y = y;
}
    virtual double evaluate() {return x->evaluate() * y->evaluate();}
    virtual std::string stringify() {return "(" +  x->stringify() + " * " + y->stringify() + ")";}

	virtual int number_of_children() {return 2;}
		virtual Base* get_child(int i) {
			if (i == 0)
				return x;
			if (i == 1)
				return y;
		}

	virtual void accept(Visitor* visitor, int index) {
			if (index == 0)
				visitor->visit_mult_begin(this);
			else if (index == 1)
				visitor->visit_mult_middle(this);
			else if (index == 2)
				visitor->visit_mult_end(this);
		}
};

#endif //__MULT_HPP__
