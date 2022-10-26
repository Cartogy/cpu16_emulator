#include <memory>

#include "emulator.hpp"

Emulator::Emulator(size_t total_ops) : cpu(), ins_mem(),  compiler() {}

void Emulator::execute_clock_cycle() {
	// Fetch first instruction
	// Check if computation has halted.
	if (*cpu.get_pc_address() > ins_mem.total_instructions() || ins_mem.total_instructions() <= 0 ) {
		std::cout << "End of Computation: No more Instructions." << std::endl;
		return;
	}

	cpu.fetch_instruction(ins_mem);
	uint16_t *pc_pointer = cpu.get_pc_address();

	uint16_t ins = cpu.get_current_instruction();
	
	// extract OpCode
	uint16_t bit_range_four = 15;
	uint16_t shift_to_op = 12;

	// isolate the opcode => 1010 0000 0000 0000
	uint16_t op_code = (bit_range_four << shift_to_op) & ins;
	// have opcode become the sole focus
	op_code = op_code >> shift_to_op;

	Operator* op_func = oper_table.get_operator(op_code);

	if (op_func == nullptr) {
		std::cout << "Invalid operator selected" << std::endl;
	} else {
		op_func->func(pc_pointer, cpu.get_registers(), ins, mem);
	}
}

void Emulator::run() {
	std::cout << "Starting Computation" << std::endl;
	while(*cpu.get_pc_address() < ins_mem.total_instructions() && ins_mem.total_instructions() > 0) {
		execute_clock_cycle();
	}

	std::cout << "End of Computation" << std::endl;

}

void Emulator::translate_instructions(std::string file_path) {
	std::vector<uint16_t> code_ins = compiler.compile_file(file_path);

	for(uint16_t ins : code_ins) {
		add_instruction(ins);
	}
}

void Emulator::add_instruction(uint16_t ins) {
	ins_mem.add_instruction(ins);
}

void Emulator::clear_instructions() {
	ins_mem.clear();
}

void Emulator::clear_cpu() {
	cpu.reset();
}

CPU& Emulator::get_cpu() {
	return cpu;
}
void Emulator::add_operator(std::unique_ptr<Operator> op) {
	// Ensure the Operator Table owns the operators.
	oper_table.add_operator(std::move(op));
}
