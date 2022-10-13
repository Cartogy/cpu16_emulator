#include "cpu.hpp"
#include <cstdint>
void CPU::exec() {
	// acquire the current instruction
	uint16_t ins = current_instruction;

	// extract OpCode
	uint16_t bit_range_four = 15;
	uint16_t shift_to_op = 12;

	// isolate the opcode => 1010 0000 0000 0000
	uint16_t op_code = (bit_range_four << shift_to_op) & ins;
	// have opcode become the sole focus
	op_code = op_code >> shift_to_op;

	// IMPLEMENT R-Type Instructions
	// Isolate the R-type bit code:
	uint16_t r_type_bit = (op_code & 4);
	
	// TODO: FInd a BETTER way of doing this. ****
	if (r_type_bit) {
		// Extract the values from the instruction
		uint16_t src_one = ((15 << 8) & ins) >> 8;
		uint16_t src_two = ((15 << 4) & ins) >> 4;
		uint16_t dst = 15 & ins;


		if (op_code == 4) {
			// ADD
			registers[dst] = registers[src_one] + registers[src_two];
		} else if (op_code == 5) {
			// Sub
			registers[dst] = registers[src_one] - registers[src_two];
		} else if (op_code == 6) {
			// Mul
			registers[dst] = registers[src_one] * registers[src_two];
		} else if (op_code == 7) {
			// Div
			registers[dst] = registers[src_one] / registers[src_two];
		}
	}

}

void CPU::reg_val(uint16_t val, uint16_t reg_index) {
	registers[reg_index] = val;
}

void CPU::fetch_instruction(InstructionMemory<uint16_t>& ins_mem) {
	current_instruction = ins_mem.get_instruction(program_counter);
	program_counter++;
}

CPU::CPU() {
	current_instruction = 0;
	program_counter = 0;

	reset();
}

uint16_t CPU::get_program_counter() {
	return program_counter;
}

uint16_t *CPU::get_pc_address() {
	uint16_t *pc_pointer = &program_counter;
	return pc_pointer;
}

void CPU::reset() {
	for(int i = 0; i < _MAX_REGISTERS; i++) {
		registers[i] = 0;
	}
}


uint16_t *CPU::get_registers() {
	return registers;
}


uint16_t CPU::get_current_instruction() {
	return current_instruction;
}
