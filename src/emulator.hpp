#ifndef EMULATOR
#define EMULATOR

#include "Cpu/cpu.hpp"
#include "OperatorTable/operator_table.hpp"
#include <cstdint>

class Emulator {
	private:
		CPU cpu;
		OperatorTable oper_table;
		InstructionMemory<uint16_t> ins_mem;
		Memory mem;
		//Parser parser;
	public:
		Emulator(uint16_t total_ops);

		// fills the OperatorTable with the appropriate instructions.
		virtual void instruction_set() = 0;

		void execute_clock_cycle();
		void run();

		// Instruction functions
		void translate_instructions(std::string file_path);
		void add_instruction(uint16_t ins);

		void add_operator(Operator &op);

		void clear_instructions();
		void clear_cpu();

		CPU& get_cpu();

};

#endif
