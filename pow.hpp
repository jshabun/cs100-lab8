#ifndef __POW_HPP__
#define __POW_HPP__

#include <iostream>
#include <string>
#include <cmath>
#include "op.hpp"

using namespace std;

class Pow: public Base {
   public:
	Pow(Base* num_base, Base* num_exp) : Base() {
		this->base_val = num_base;
		this->exp_val = num_exp;
	}
	
	virtual double evaluate() {
		return (pow(base_val->evaluate(), exp_val->evaluate()));
	}
	
	virtual std::string stringify() {
		return ("(" + base_val->stringify() + " ** " + exp_val->stringify() + ")" );
	}
	
	virtual int number_of_children() {return 2;}
		virtual Base* get_child(int i) {
			if (i == 0)
				return base_val;
			if (i == 1)
				return exp_val;
		}

	virtual void accept(Visitor* visitor, int index) {
			if (index == 0)
				visitor->visit_pow_begin(this);
			else if (index == 1)
				visitor->visit_pow_middle(this);
			else if (index == 2)
				visitor->visit_pow_end(this);
		}

   private:
	Base* base_val;
	Base* exp_val;
};

#endif //__POW_HPP__
