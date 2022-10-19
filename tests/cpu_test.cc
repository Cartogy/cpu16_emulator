#include <gtest/gtest.h>

#include "cpu.hpp"
#include "InstructionMemory/instruction_memory.hpp"

class CPUTest : public ::testing::Test {
	protected:
		CPU cpu;
		InstructionMemory<uint16_t> ins_mem;

	void SetUp() override {
		cpu = CPU();
	}
};

TEST_F(CPUTest, CPUCreation) {
	EXPECT_EQ(cpu.get_current_instruction(), 0);
	EXPECT_EQ(cpu.get_program_counter(), 0);

	for(int i = 0; i < _MAX_REGISTERS; i++) {
		EXPECT_EQ(0,cpu.get_registers()[i]);
	}
}

TEST_F(CPUTest, RegisterValues) {
	cpu.reg_val(12,0);
	cpu.reg_val(1,1);
	cpu.reg_val(65,5);

	EXPECT_EQ(12, cpu.get_registers()[0]);
	EXPECT_EQ(1, cpu.get_registers()[1]);
	EXPECT_EQ(65, cpu.get_registers()[5]);
}

TEST_F(CPUTest, CPUInstructionMemory) {
	EXPECT_TRUE(false);
}

