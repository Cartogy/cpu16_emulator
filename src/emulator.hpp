#include "Cpu/cpu.hpp"
#include <cstdint>

class Emulator16 {
	private:
		CPU cpu;
		InstructionMemory<uint16_t> ins_mem;
		//Parser parser;
	public:
		void run();
		void translate_instructions(std::string file_path);
		void add_instruction(uint16_t ins);

		void clear_instructions();
		void clear_cpu();

};
