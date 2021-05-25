#ifndef __LATEX_TEST_HPP__
#define __LATEX_TEST_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "pow.hpp"
#include "print.hpp"

TEST(LatexTest, Sub)
{
	Base* add1 = new Sub(new Op(12),new Op(6));
	EXPECT_EQ(print_latex(add1),"${({12.000000}-{6.000000})}$" ); 
	delete add1;
}

TEST(LatexTest, Mult)
{
        Base* add1 = new Mult(new Op(9),new Op(6));
        EXPECT_EQ(print_latex(add1),"${({9.000000}\\cdot{6.000000})}$" );
        delete add1;
}

TEST(LatexTest, Add)
{
        Base* add1 = new Add(new Op(9),new Op(10));
        EXPECT_EQ(print_latex(add1),"${({9.000000}+{10.000000})}$" );
        delete add1;
}

TEST(LatexTest, Div)
{
        Base* add1 = new Div(new Op(10),new Op(5));
        EXPECT_EQ(print_latex(add1),"${\\frac{10.000000}{5.000000}}$" );
        delete add1;
}


TEST(LatexTest, AddSubSub)
{
        Base* add1 = new Add(new Op(8),new Sub(new Op(2), new Op(3)));	
        EXPECT_EQ(print_latex(add1),"${({8.000000}+{({2.000000}-{3.000000})})}$" );
        delete add1;
}

TEST(LatexTest, Pow)
{
        Base* add1 = new Pow(new Op(7),new Op(10));
        EXPECT_EQ(print_latex(add1),"${({7.000000}^{10.000000})}$" );
        delete add1;
}

TEST(LatexTest, DivMultPow)
{
        Base* add1 = new Div(new Mult(new Op(5),new Op(9)),new Pow(new Op(3), new Op(1)));
        EXPECT_EQ(print_latex(add1),"${\\frac{({5.000000}\\cdot{9.000000})}{({3.000000}^{1.000000})}}$" );
        delete add1;
}

#endif //__LATEX_PRINT_HPP__
