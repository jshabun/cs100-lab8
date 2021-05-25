#ifndef __VISITMATHML_HPP__
#define __VISITMATHML_HPP__

#include <iostream>
#include <string>
#include "visitor.hpp"

using namespace std;

class VisitMathMl : public Visitor {
	private:
		string exp;
		int var1 = 0;
		int var2 = 0;

	pubic:
		void visit_op(Op* node) {
			for (int i = 0; i < var1; i++) {
				exp = exp + "\t";
			}
			
			exp = exp + "<cn>" + node->stringify() + "</cn>\n";
		}
	
		void visit_rand(Rand* node) {
			for (int i = 0; i < var1; i+=) {
				exp = exp + "\t";
			}
			
			exp = exp + "<cn>" + node ->stringify() + "</cn>\n";
		}
		
		void visit_add_begin(Add* node) {
			var1++;
			for (int i = 0; i < var1; i++) {
				exp = exp + "\t";
			}

			exp = exp + "<apply>\n";
			var1++;

			for (int i = 0; i < var1; i++) {
				exp = exp + "\t";
			}
			
			exp = exp + "<plus/>\n";
		}
		
		void visit_add_middle(Add* node) {}
		
		void visit_add_end(Add* node) {
			var1 = var1 - 2;
			for (int i = 0; i < var1; i++) {
				exp = exp + "\t}";
			}

			exp = exp + "\t</apply>\n";		
		}
		
        void visit_sub_begin(Sub* node) {
			var1++;
			for (int i = 0; i < var1; i++) {
				exp = exp + "\t";
			}

			exp = exp "<minus/>\n";
		}

        void visit_sub_middle(Sub* node) {}

        void visit_sub_end(Sub* node) {
			var1 = var1 - 2;
			for (int i = 0; i < var1; i++) {
				exp = exp + "\t";
			}

			exp = exp + "\t</apply>\n";
		}

        void visit_mult_begin(Mult* node) {
			var1++;
			for (int i = 0; i < var1; i++) {
				exp = exp + "\t";
			}

			exp = exp + "<apply>\n";
			var1++;

			for (int i = 0; i < var1; i++) {
				exp = exp + "\t";
			}

			exp = exp + "<times/>\n";
		}

        void visit_mult_middle(Mult* node) {}

        void visit_mult_end(Mult* node) {
			var1 = var1 - 2;
			for (int i = 0; i < var1; i++) {
				exp = exp + "\t";
			}

			exp = exp + "\t</apply>\n";
		}

        void visit_div_begin(Div* node) {
			var1++;
			for (int i = 0; i < var1; i++) {
				exp = exp + "\t";
			}

			exp = exp + "<apply>\n";
			var1++;

			for (int i = 0; i < var1; i++) {
				exp = exp + "\t";
			}

			exp = exp + "<divide/>\n";
		}

        void visit_div_middle(Div* node) {}

        void visit_div_end(Div* node) {
			var1 = var1 - 2;
			for (int i = 0; i < var1; i++) {
				exp = exp + "\t";
			}

			exp = exp + "\t</apply>\n";
		}

        void visit_pow_begin(Pow* node) {
			var1++;
			for (int i = 0; i < var1; i++) {
				exp = "\t";
			}

			exp = exp + "<apple>\n";			
			var1++;

			for (int i = 0; i < var1; i++) {
				exp = exp + "\t";
			}

			exp = exp + "<power/>\n";
		}

        void visit_pow_middle(Pow* node) {}

        void visit_pow_end(Pow* node) {
			var1 = var1 - 2;
			for (int i = 0; i < var1; i++) {
				exp = exp + "\t";
			}

			exp = exp + "\t</apply>\n";
		}
		
		string getString() {
			return exp;
		}
};

#endif //__VISITMATHML_HPP__
