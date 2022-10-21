#include <gtest/gtest.h>

#include "OperatorTable/operator_table.hpp"
#include "Operator/operator.hpp"
#include "emu_operator.hpp"
#include "emu_utils.hpp"

class OperatorTableTest : public ::testing::Test {
	protected:
		OperatorTable oper_table = OperatorTable(10);
		std::unique_ptr<Operator> addf;
		std::unique_ptr<Operator> subf;
		std::unique_ptr<Operator> mulf;

		Memory mem;
		uint16_t registers[10];


	void SetUp() override  {
		addf = std::unique_ptr<Operator>(new OpAdd(1));
		subf = std::unique_ptr<Operator>(new OpSub(2));
		mulf = std::unique_ptr<Operator>(new OpMul(3));
		
		for(int i = 0; i < 10; i++) {
			registers[i] = 0;
		}
		// Add starting register.
		registers[0] = 1;
		registers[1] = 1;
	}
};

TEST_F(OperatorTableTest, AddingOperators) {

	oper_table.add_operator(std::move(addf));	
	oper_table.add_operator(std::move(subf));	
	oper_table.add_operator(std::move(mulf));	

	EXPECT_EQ(1, oper_table.get_operator(1)->get_id());
	EXPECT_EQ(2, oper_table.get_operator(2)->get_id());
	EXPECT_EQ(3, oper_table.get_operator(3)->get_id());
}

TEST_F(OperatorTableTest, OperatorFunctionality) {
	oper_table.add_operator(std::move(addf));	
	oper_table.add_operator(std::move(subf));	
	oper_table.add_operator(std::move(mulf));	



	uint16_t pc = 0;
	uint16_t add_ins = create_r_ins(0, 0, 1, 2);
	uint16_t mul_ins = create_r_ins(0, 2, 2, 2);
	uint16_t sub_ins = create_r_ins(0, 2, 1, 2);

	oper_table.get_operator(1)->func(&pc, registers, add_ins, mem);
	EXPECT_EQ(2, registers[2]);

	oper_table.get_operator(3)->func(&pc, registers, mul_ins, mem);
	EXPECT_EQ(4, registers[2]);

	oper_table.get_operator(2)->func(&pc, registers, sub_ins, mem);
	EXPECT_EQ(3, registers[2]);

}

