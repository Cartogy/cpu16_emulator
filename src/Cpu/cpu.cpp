#include "cpu.hpp"
#include <cstdint>
void CPU::exec() {
	// acquire the current instruction
	uint16_t ins = current_instruction;

}

void CPU::reg_val(uint16_t val, uint16_t reg_index) {
	registers[reg_index] = val;
}

void CPU::fetch_instruction(InstructionMemory<uint16_t>& ins_mem) {
}

CPU::CPU() {
	current_instruction = 0;
	program_counter = 0;
	for(int i = 0; i < _MAX_REGISTERS; i++) {
		registers[i] = 0;
	}
}
