#include "emu_utils.hpp"
#include "Cpu/cpu.hpp"
#include <cstdint>

int main() {
	CPU cpu;
	InstructionMemory<uint16_t> ins_mem;

	uint16_t add_ins_one = create_r_ins(4, 1, 2, 2);
	cpu.reg_val(1, 1);

	ins_mem.add_instruction(add_ins_one);
	ins_mem.add_instruction(add_ins_one);
	ins_mem.add_instruction(add_ins_one);
	ins_mem.add_instruction(add_ins_one);
	ins_mem.add_instruction(add_ins_one);

	cpu.fetch_instruction(ins_mem);
	cpu.exec();
	cpu.fetch_instruction(ins_mem);
	cpu.exec();
	cpu.fetch_instruction(ins_mem);
	cpu.exec();
	cpu.fetch_instruction(ins_mem);
	cpu.exec();
	cpu.fetch_instruction(ins_mem);
	cpu.exec();

	return 0;
}
