
#include "instruction_memory.hpp"

InstructionMemory::InstructionMemory() {
	instruction_memory.reserve(_MAX_INSTRUCTIONS);
}

// Has no Error Checking!
uint16_t InstructionMemory::get_instruction(uint16_t index){
	return instruction_memory[index];
}
void InstructionMemory::add_instruction(uint16_t ins) {
	instruction_memory.push_back(ins);
}
uint16_t InstructionMemory::total_instructions() {
	return instruction_memory.size();
}
