#include "machinecodegenerator.hpp"

MachineCodeGenerator::MachineCodeGenerator() {
	instruction_table["add"] = 4;
	instruction_table["sub"] = 5;
	instruction_table["mul"] = 6;
	instruction_table["div"] = 7;

	instruction_table["load"] = 8;
	instruction_table["store"] = 9;
	instruction_table["addi"] = 10;
	instruction_table["subi"] = 11;
	instruction_table["beq"] = 12;

	instruction_table["jmp"] = 2;
}


std::vector<uint16_t> MachineCodeGenerator::generate_code(std::vector<ParserNode *> nodes) {
	std::vector<uint16_t> instruction_codes;

	for(int i = 0; i < nodes.size(); i++) {
		ParserNode *node;
		uint16_t code = node->encoding(instruction_table[node->get_node_type()]);

		instruction_codes.push_back(code);
	}

	return instruction_codes;
}
