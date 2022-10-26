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

MachineCodeGenerator::~MachineCodeGenerator() {
}

std::vector<uint16_t> MachineCodeGenerator::generate_code(std::vector<ParserNode *> nodes) {
	std::vector<uint16_t> instruction_codes;

	for(int i = 0; i < nodes.size(); i++) {
		ParserNode *node = nodes[i];
		uint16_t code = 0;
		if (instruction_table.count(node->get_node_type()) > 0) {
			code = node->encoding(instruction_table[node->get_node_type()]);
		} else {
			std::cout << "ERROR:Invalid Node Type" << std::endl;
		}

		instruction_codes.push_back(code);
	}

	return instruction_codes;
}
