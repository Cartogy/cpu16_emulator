#ifndef ASM_PARSER
#define ASM_PARSER

#include "parsernode.hpp"
#include "POperTable/popertable.hpp"
#include "../Tokenizer/tokenizer.hpp"

#include <iostream>


class ASMParser {
	private:
		PoperTable poper_table;
		//ArchitectureSpecification arch_spec;
		InsCategory* get_category(std::string ins_str);


		void add_category(std::unique_ptr<InsCategory> ins_cat);
		bool valid_instruction(std::string ins_str);

		ParserNode * parse_line(TokenLine * token_line, RCategory* ins_cat, size_t line_position);
		ParserNode * parse_line(TokenLine * token_line, ICategory* ins_cat, size_t line_position);
		ParserNode * parse_line(TokenLine * token_line, JCategory* ins_cat, size_t line_position);
		ParserNode * parse_line(TokenLine * token_line, InsCategory* ins_cat, size_t line_position);
	public:

		ASMParser();
		~ASMParser();
		bool valid_register(std::string reg_str);
		std::vector<ParserNode *> parse(std::vector<TokenLine *> tokens);

};

#endif
