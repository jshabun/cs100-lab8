#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "pow.hpp"

TEST(FunctionTest, AddGetChild)
{
        Base *seven = new Op(7);
        Base *three = new Op(3);
        Base *add = new Add(one,three);

        EXPECT_EQ("7.000000", add->get_child(0)->stringify());
        EXPECT_EQ("3.000000", add->get_child(1)->stringify());
        EXPECT_EQ(1.000000, add->get_child(0)->evaluate());
        EXPECT_EQ(3.000000, add->get_child(1)->evaluate());

        delete add;
		delete seven;
		delete three;
}

TEST(FunctionTest, AddNumOfChild)
{
        Base *one = new Op(1);
        Base *three = new Op(3);
        Base *add = new Add(one,three);

        EXPECT_EQ(2, add->number_of_children());

        delete add;
		delete one;
		delete three;
}

TEST(FunctionTest, SubGetChild_LeftOperandAdd)
{
        Base *left = new Add(new Op(4), new Op(5));
        Base *right = new Op(3);
        Base *sub = new Sub(left, right);

        EXPECT_EQ("4.000000 + 5.000000)", sub->get_child(0)->stringify());
        EXPECT_EQ("3.000000", sub->get_child(1)->stringify());
        EXPECT_EQ(9.000000, sub->get_child(0)->evaluate());
        EXPECT_EQ(3.000000, sub->get_child(1)->evaluate());

        delete sub;
		delete left;
		delete right;
}
TEST(FunctionTest, SubNumOfChild)
{
        Base *left = new Add(new Op(4), new Op(5));
        Base *right = new Op(3);
        Base *sub = new Sub(left, right);

        EXPECT_EQ(2, sub->number_of_children());

        delete sub;
		delete left;
		delete right;
}

TEST(FunctionTest, MultGetChild_RightOperandSub)
{
        Base *left = new Add(new Op(13), new Op(22));
        Base *right = new Sub(new Op(27), new Op(42));
        Base *mult = new Mult(left, right);

        EXPECT_EQ("(13.000000 + 22.000000)", mult->get_child(0)->stringify());
        EXPECT_EQ("(27.000000 - 42.000000)", mult->get_child(1)->stringify());
        EXPECT_EQ(35.000000, mult->get_child(0)->evaluate());
        EXPECT_EQ(-15.000000, mult->get_child(1)->evaluate());

        delete mult;
		delete left;
		delete right;
}

TEST(FunctionTest, MultNumOfChild)
{
        Base *left = new Add(new Op(13), new Op(22));
        Base *right = new Sub(new Op(27), new Op(42));
        Base *mult = new Mult(left, right);

        EXPECT_EQ(2, mult->number_of_children());

        delete mult;
		delete left;
		delete right;
}

TEST(FunctionTest, DivGetChild)
{
        Base *left = new Mult(new Op(15), new Op(5));
        Base *right = new Mult(new Op(3), new Op(49));
        Base *div = new Div(left, right);

        EXPECT_EQ("(15.000000 * 5.000000)", div->get_child(0)->stringify());
        EXPECT_EQ("(3.000000 * 49.000000)", div->get_child(1)->stringify());
        EXPECT_EQ(75.000000, div->get_child(0)->evaluate());
        EXPECT_EQ(147.000000, div->get_child(1)->evaluate());

        delete div;
}
TEST(FunctionTest, DivNumberOfChildren)
{
        Base *left = new Mult(new Op(15), new Op(5));
        Base *right = new Mult(new Op(3), new Op(49));
        Base *div = new Div(left, right);

        EXPECT_EQ(2, div->number_of_children());

        delete div;
		delete left;
		delete right;
}

TEST(FunctionTest, PowGetChild)
{
        Base *left = new Sub(new Op(12), new Op(55));
        Base *right = new Add(new Op(67), new Op(-25));
        Base *pow = new Pow(left, right);

        EXPECT_EQ("(12.000000 - 55.000000)", pow->get_child(0)->stringify());
        EXPECT_EQ("(67.000000 + -25.000000)", pow->get_child(1)->stringify());
        EXPECT_EQ(-43.000000, pow->get_child(0)->evaluate());
        EXPECT_EQ(42.000000, pow->get_child(1)->evaluate());

        delete pow;
		delete left;
		delete right;
}

TEST(FunctionTest, PowNumOfChild)
{
        Base *left = new Sub(new Op(12), new Op(55));
        Base *right = new Add(new Op(67), new Op(-25));
        Base *pow = new Pow(left, right);

        EXPECT_EQ(2, pow->number_of_children());

        delete pow;
		delete left;
		delete right;
}

TEST(FunctionTest, OpGetChild)
{
        Base *op = new Op(834);
        EXPECT_EQ(nullptr, op->get_child(0));

        delete op;
}

TEST(FunctionTest, OpNumOfChild)
{
        Base *op = new Op(7856);

        EXPECT_EQ(0, op->number_of_children());

        delete op;
}

TEST(FunctionTest, RandGetChild)
{
        Base *rand = new Rand();
        EXPECT_EQ(nullptr, rand->get_child(0));

        delete rand;
}

TEST(FunctionTest, RandNumberOfChildren)
{
        Base *rand = new Rand();

        EXPECT_EQ(0, rand->number_of_children());

        delete rand;
}

#endif // __ITERATOR_TEST_HPP__
