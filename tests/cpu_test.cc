#include <gtest/gtest.h>

#include "cpu.hpp"
#include "InstructionMemory/instruction_memory.hpp"

class CPUTest : public ::testing::Test {
	protected:
		CPU cpu;
		InstructionMemory<uint16_t> ins_mem;

	void SetUp() override {
		cpu = CPU();
		ins_mem = InstructionMemory<uint16_t>();
		ins_mem.add_instruction(10);
		ins_mem.add_instruction(18);
		ins_mem.add_instruction(30);
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
	cpu.fetch_instruction(ins_mem);
	EXPECT_EQ(10, cpu.get_current_instruction());
	EXPECT_EQ(1, *(cpu.get_pc_address()));

	cpu.fetch_instruction(ins_mem);
	EXPECT_EQ(18, cpu.get_current_instruction());
	EXPECT_EQ(2, *(cpu.get_pc_address()));

	cpu.fetch_instruction(ins_mem);
	EXPECT_EQ(30, cpu.get_current_instruction());
	EXPECT_EQ(3, *(cpu.get_pc_address()));
}

