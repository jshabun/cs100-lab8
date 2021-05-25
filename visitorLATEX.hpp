#ifndef __VISITORLATEX_HPP__
#define __VISITORLATEX_HPP__

#include "visitor.hpp"

class VisitorLaTeX : public Visitor {
	private:
		std::string exp;
	
	public:
		void visit_op(Op* node) { exp += "{" + node->stringify() + "}"; }
		void visit_rand(Rand* node) { exp += "{" + node->stringify() + "}"; }

		void visit_add_begin(Add* node) { exp += "{("; }
		void visit_add_middle(Add* node) { exp += "+"; }
		void visit_add_end(Add* node) { exp += ")}"; }
		void visit_sub_begin(Sub* node) { exp += "{("; }
		void visit_sub_middle(Sub* node) { exp += "-"; }
		void visit_sub_end(Sub* node) { exp += ")}"; }
		void visit_mult_begin(Mult* node) { exp += "{("; }
		void visit_mult_middle(Mult* node) { exp += "\\cdot"; }
		void visit_mult_end(Mult* node) { exp += ")}"; }
		void visit_div_begin(Div* node) { exp += "{\\frac"; }
		void visit_div_middle(Div* node) { }
		void visit_div_end(Div* node) { exp += "}"; }
		void visit_pow_begin(Pow* node) { exp += "{("; }
		void visit_pow_middle(Pow* node) { exp += "^"; }
		void visit_pow_end(Pow* node) {exp += ")}"; }

		std::string getString() { return exp; }
};

#endif
