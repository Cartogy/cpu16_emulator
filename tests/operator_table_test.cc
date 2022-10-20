#include <gtest/gtest.h>

#include "OperatorTable/operator_table.hpp"
#include "Operator/operator.hpp"
#include "emu_operator.hpp"

class OperatorTableTest : public ::testing::Test {
	protected:
		OperatorTable oper_table = OperatorTable(10);
		std::unique_ptr<Operator> addf;
		std::unique_ptr<Operator> subf;
		std::unique_ptr<Operator> mulf;


	void SetUp() override  {
		std::unique_ptr<Operator> addf(new OpAdd(1));
		std::unique_ptr<Operator> subf(new OpSub(2));
		std::unique_ptr<Operator> mulf(new OpMul(3));
	}
};

TEST_F(OperatorTableTest, AddingOperators) {

	oper_table.add_operator(std::move(addf));	
	oper_table.add_operator(std::move(subf));	
	oper_table.add_operator(std::move(mulf));	

	EXPECT_EQ(1, *(oper_table.get_operator(1)));
	EXPECT_EQ(2, *(oper_table.get_operator(2)));
	EXPECT_EQ(3, *(oper_table.get_operator(3)));
}

TEST_F(OperatorTableTest, OperatorFunctionality) {
	oper_table.add_operator(std::move(addf));	
	oper_table.add_operator(std::move(subf));	
	oper_table.add_operator(std::move(mulf));	
}

