#include "gtest.h"
#include "../Stack/Calculator.h"
#include "../Stack/Calculator.cpp"

TEST(Calculator, can_get_infix)
{
	Calculator calc;
	ASSERT_NO_THROW(calc.GetExpression());
}

TEST(Calculator, can_get_postfix)
{
	Calculator calc;
	ASSERT_NO_THROW(calc.GetPostfix());
}

TEST(Calculator, can_set_formula)
{
	Calculator calc;
	string str = "4-3";
	ASSERT_NO_THROW(calc.SetExpression(str));
}

TEST(Calculator, can_set_a_string_to_calculator)
{
	Calculator calc;
	string str = "1+5-2";
	ASSERT_NO_THROW(calc.SetFormula(str));
}

TEST(Calculator, can_check_wrong_brackets)
{
	Calculator calc;
	string str = "8-(3+2";
	ASSERT_ANY_THROW(calc.SetFormula(str));
}

TEST(Calculator, can_check_right_brackets)
{
	Calculator calc;
	string str = "8-(3+2)";
	ASSERT_NO_THROW(calc.SetFormula(str));
}

TEST(Calculator, can_add)
{
	Calculator calc;
	calc.SetFormula("3+2");
	calc.ToPostfix();
	EXPECT_EQ(5, calc.CalcPostfix());
}

TEST(Calculator, can_subtract)
{
	Calculator calc;
	calc.SetFormula("3-2");
	calc.ToPostfix();
	EXPECT_EQ(1, calc.CalcPostfix());
}

TEST(Calculator, can_multiply)
{
	Calculator calc;
	calc.SetFormula("3*2");
	calc.ToPostfix();
	EXPECT_EQ(6, calc.CalcPostfix());
}

TEST(Calculator, can_divide)
{
	Calculator calc;
	calc.SetFormula("3/2");
	calc.ToPostfix();
	EXPECT_EQ(1.5, calc.CalcPostfix());
}

TEST(Calculator, can_pow)
{
	Calculator calc;
	calc.SetFormula("3^2");
	calc.ToPostfix();
	EXPECT_EQ(9, calc.CalcPostfix());
}

TEST(Calculator, can_do_all_operations_together)
{
	Calculator calc;
	calc.SetFormula("5+4-9/3*2");
	calc.ToPostfix();
	EXPECT_EQ(3, calc.CalcPostfix());
}

TEST(Calculator, cant_calculate_expression_with_wrong_number_of_operations)
{
	Calculator calc;
	calc.SetFormula("3--2");
	calc.ToPostfix();
	EXPECT_ANY_THROW(calc.CalcPostfix());
}
