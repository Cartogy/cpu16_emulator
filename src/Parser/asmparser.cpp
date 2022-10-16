#include "asmparser.hpp"


InsCategory* ASMParser::get_category(std::string ins_str) {
	return poper_table.get_category(ins_str);
}

bool ASMParser::valid_register(std::string reg_str) {
	return arch_spec.valid_reg(reg_str);
}


bool ASMParser::valid_instruction(std::string ins_str) {
	return get_category(ins_str) != nullptr;
}

std::vector<ParsedLine> ASMParser::parse(std::vector<Tokenizer::Token> tokens) {
	size_t current_line = 0;
	size_t total_tokens = tokens.size();

	std::vector<ParsedLine> parsed_lines;
	while(current_line < total_tokens) {
		Tokenizer::token first_token = tokens[current_line];

		// 1) Check if valid token
		// 1.3) Check if valid instruction
		// 1.5) Check if valid register
		// 2) Get categories
		// 3) Parse Line
		ParsedLine node = parse_line(tokens, op_cat, current_line);
		parsed_lines.push_back(node);
		current_line += NODES_PER_LINE;

	}

}
