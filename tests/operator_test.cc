#include <gtest/gtest.h>

#include "Operator/operator.hpp"
#include "emu_operator.hpp"
#include "emu_utils.hpp"

#define TEST_MAX_REGISTERS 10


class OperatorTest : public ::testing::Test {
	protected:
		// R-Type instructions
		OpAdd addf = OpAdd(1);
		OpSub subf = OpSub(2);
		OpDiv divf = OpDiv(3);
		OpMul mulf = OpMul(4);
		// I-Type instructions
		OpLoad loadf = OpLoad(5);
		OpStore storef = OpStore(6);
		OpAddI addif = OpAddI(7);
		OpSubI subif = OpSubI(8);
		OpBranchEqual brancheqf = OpBranchEqual(9);
		// J-Type instructions
		OpJmp jmpf = OpJmp(10);

		uint16_t registers[TEST_MAX_REGISTERS];
		Memory mem;
	void SetUp() override {
		for(int i = 0; i < TEST_MAX_REGISTERS; i++) {
			registers[i] = 0;
		}
		registers[0] = 1;
		registers[1] = 2;

	}

};


TEST_F(OperatorTest, Constructing) {
	EXPECT_EQ(1,addf.get_id());
	EXPECT_EQ(2,subf.get_id());
	EXPECT_EQ(3,divf.get_id());
	EXPECT_EQ(4,mulf.get_id());
	EXPECT_EQ(5,loadf.get_id());
	EXPECT_EQ(6,storef.get_id());
	EXPECT_EQ(7,addif.get_id());
	EXPECT_EQ(8,subif.get_id());
	EXPECT_EQ(9,brancheqf.get_id());
	EXPECT_EQ(10,jmpf.get_id());
}

TEST_F(OperatorTest, RInstructions) {
	uint16_t test_pc = 0;
	uint16_t reg_test_one = 2;
	uint16_t reg_test_two = 3;

	uint16_t add_ins = create_r_ins(0,0,1,2);

	addf.func(&test_pc, registers, add_ins, mem);
	EXPECT_EQ(3,registers[reg_test_one]);

	uint16_t sub_ins = create_r_ins(0,2,0,2);
	subf.func(&test_pc, registers, sub_ins, mem);
	EXPECT_EQ(2,registers[reg_test_one]);

	uint16_t mul_ins = create_r_ins(0,1,2,2);
	mulf.func(&test_pc, registers, mul_ins, mem);
	EXPECT_EQ(4, registers[reg_test_one]);

	uint16_t div_ins = create_r_ins(0,2,1,2);
	divf.func(&test_pc, registers, div_ins, mem);
	EXPECT_EQ(2, registers[reg_test_one]);
}
