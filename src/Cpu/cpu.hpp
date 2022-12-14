#ifndef MY_CPU
#define MY_CPU

#include <cstdint>
#include <iostream>
#include "InstructionMemory/instruction_memory.hpp"

#define BITS 16
// 16 possible registers due to OpCode being 4 bits: 2^4 => 16
#define _MAX_REGISTERS (2*2*2*2)

class CPU {
	private:
		uint16_t registers[_MAX_REGISTERS];
		uint16_t current_instruction;
		uint16_t program_counter;
	public:
		CPU();
		void exec();
		void fetch_instruction(InstructionMemory<uint16_t>& ins_mem);
		void reg_val(uint16_t val, uint16_t reg_index);
		uint16_t get_program_counter();
		uint16_t *get_registers();
		uint16_t *get_pc_address();
		uint16_t get_current_instruction();

		void reset();
};
#endif
