#include "emu_utils.hpp"
#include "Cpu/cpu.hpp"
#include "my_emulator.cpp"
#include <cstdint>

int main() {
	CPU cpu;
	InstructionMemory<uint16_t> ins_mem;

	uint16_t add_ins_one = create_r_ins(4, 1, 2, 2);

	Emulator16 emu16(15);
	emu16.add_instruction(add_ins_one);
	emu16.add_instruction(add_ins_one);
	emu16.add_instruction(add_ins_one);
	emu16.add_instruction(add_ins_one);

	emu16.get_cpu().reg_val(1, 1);

	emu16.execute_clock_cycle();
	emu16.execute_clock_cycle();

	return 0;
}
