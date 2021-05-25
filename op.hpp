#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "visitor.hpp"

using namespace std;

class Op : public Base {
     protected:
        double val;

     public:
        Op(double value) : Base() {this->val = value;}
        double evaluate() {return val; }
        std::string stringify() { return to_string(val); }
		virtual int number_of_children() {return 0;}
		virtual Base* get_child(int i) {return nullptr;}
		virtual void accept(Visitor* visitor, int index) {visitor->visit_op(this);}
};


#endif //__OP_HPP__

