#ifndef ASM_PARSER
#define ASM_PARSER

#include "parsernode.hpp"
#include "POperTable/popertable.hpp"
#include "../Tokenizer/tokenizer.hpp"

#include <iostream>

#define NODE_PER_LINE 3

class ASMParser {
	private:
		PoperTable poper_table;
		ArchitectureSpecification arch_spec;
		InsCategory* get_category(std::string ins_str);
		bool valid_register(std::string reg_str);
		bool valid_instruction(std::string ins_str);

		ParsedLine parse_line(std::vector<Tokenizer::Token> token_line, RCategory ins_cat, size_t line_position);
		ParsedLine parse_line(std::vector<Tokenizer::Token> token_line, ICategory ins_cat, size_t line_position);
		ParsedLine parse_line(std::vector<Tokenizer::Token> token_line, JCategory ins_cat, size_t line_position);
	public:

		std::vector<ParsedLine> parse(std::vector<Tokenizer::Token> tokens);

};

#endif
