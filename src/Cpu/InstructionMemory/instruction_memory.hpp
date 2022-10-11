
#include <vector>
#include <iostream>

#define _MAX_INSTRUCTIONS 256

class InstructionMemory {
	private:
		std::vector<uint16_t> instruction_memory;
	public:
		InstructionMemory();
		uint16_t get_instruction(uint16_t index);
		void add_instruction(uint16_t ins);
		uint16_t total_instructions();
};

