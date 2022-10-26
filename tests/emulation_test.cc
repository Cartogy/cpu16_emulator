#include <gtest/gtest.h>

#include "emu16.hpp"


class EmulatorTest : public ::testing::Test {
	protected:
		Emulator16 emu = Emulator16(16);

	void SetUp() {
		emu.get_cpu().reg_val(1, 1);
	}
};


TEST_F(EmulatorTest, Execution) {
	emu.translate_instructions("test_three_asm.asm");
	emu.run();

	uint16_t *regs = emu.get_cpu().get_registers();
	EXPECT_EQ(2, emu.get_cpu().get_registers()[2]);
	EXPECT_EQ(4, emu.get_cpu().get_registers()[3]);
	EXPECT_EQ(6, emu.get_cpu().get_registers()[4]);
}
