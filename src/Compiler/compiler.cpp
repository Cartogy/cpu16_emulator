#include <sstream>
#include <fstream>
#include "compiler.hpp"

Compiler::Compiler() : tokenizer(), parser(), machine_code_gen() {
}

Compiler::~Compiler() {
}

std::vector<uint16_t> Compiler::compile_source(std::string source) {
	std::vector<uint16_t> code_list;
	std::vector<TokenLine *> toks = tokenize_source(source);
	std::vector<ParserNode *> p_nodes = parser.parse(toks);
	code_list = machine_code_gen.generate_code(p_nodes);

	// Clean code
	for(int i = 0; i < toks.size(); i++) {
		delete toks[i];
	}

	for(int i = 0; i < p_nodes.size(); i++) {
		ParserNode * p_node = p_nodes[i];
		delete p_node;
	}

	return code_list;
}

std::vector<uint16_t> Compiler::compile_file(std::string file) {
	std::ifstream input_stream;
	input_stream.open(file);

	std::vector<uint16_t> code;
	std::string line;
	std::stringstream src_string;
	if (input_stream.is_open()) {
		src_string << input_stream.rdbuf();

		code = compile_source(src_string.str());
	}

	return code;
}
