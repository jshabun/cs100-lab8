#ifndef __VISITMATHML_TEST_HPP__
#define __VISITMATHML_TEST_HPP__

#include <iostream>

#include "gtest/gtest.h"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "pow.hpp"
#include "print.hpp"

using namespace std;

TEST(MathML, 45minus20) {
	Base* sub = new Sub(new Op(45), new Op(20));
	EXPECT_EQ("<math>\n\t<apply>\n\t\t<minus/>\n\t\t<cn>45.000000</cn>\n\t\t<cn>20.000000</cn>\n\t</apply>\n</math>", print_mathML(sub));
	delete sub;
}

TEST(MathML, 5times6) {
	Base* mult = new Mult(new Op(5), new Op(6));
	EXPECT_EQ("<math>\n\t<apply>\n\t\t<times/>\n\t\t<cn>5.000000</cn>\n\t\t<cn>6.000000</cn>\n\t</apply>\n</math>", print_mathML(mult));
	delete mult;
}

TEST(MathML, 7plus10) {
	Base* add = new Add(new Op(7), new Op(10));
	EXPECT_EQ("<math>\n\t<apply>\n\t\t<plus/>\n\t\t<cn>7.000000</cn>\n\t\t<cn>10.000000</cn>\n\t</apply>\n</math>", print_mathML(add));
	delete add;
}

TEST(MathML, 8div4) {
	Base* div = new Div(new Op(8), new Op(4));
	EXPECT_EQ("<math>\n\t<apply>\n\t\t<divide/>\n\t\t<cn>8.000000</cn>\n\t\t<cn>4.000000</cn>\n\t</apply>\n</math>", print_mathML(div));
	delete div;
}

TEST(MathML, 3plus6minus1) {
	Base* add3 = new Add(new Op(3), new Sub(new Op(6), new Op(1)));
	EXPECT_EQ("<math>\n\t<apply>\n\t\t<plus/>\n\t\t<cn>3.000000</cn>\n\t\t\t<apply>\n\t\t\t\t<minus/>\n\t\t\t\t<cn>6.000000</cn>\n\t\t\t\t<cn>1.000000</cn>\n\t\t\t</apply>\n\t</apply>\n</math>",print_mathML(add3));
	delete add3;
}

TEST(MathML, 2pow2) {
	Base* pow = new Pow(new Op(2), new Op(2));
	EXPECT_EQ("<math>\n\t<apple>\n\t\t<power/>\n\t\t<cn>2.000000</cn>\n\t\t<cn>2.000000</cn>\n\t</apply>\n</math>", print_mathML(pow));
	delete pow;
}

TEST(MathML, multDivPow) {
	Base* multDiv = new Mult(new Div(new Op(2),new Op(5)),new Pow(new Op(5), new Op(2)));
	EXPECT_EQ("<math>\n\t<apple>\n\t\t\t\t<power/>\n\t\t\t\t<cn>5.000000</cn>\n\t\t\t\t<cn>2.000000</cn>\n\t\t\t</apply>\n\t</apply>\n</math>", print_mathML(multDiv));
    delete multDiv;
}

#endif //__VISITMATHML_TEST_HPP__
