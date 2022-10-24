#include <sstream>
#include "asmparser.hpp"

ASMParser::ASMParser() : poper_table(){

}
ASMParser::~ASMParser() {

}

InsCategory* ASMParser::get_category(std::string ins_str) {
	return poper_table.get_category(ins_str);
}

// Extract to its own class.
bool ASMParser::valid_register(std::string reg_str) {
	//return arch_spec.valid_reg(reg_str);
	std::map<std::string, bool> regs;
	regs["$r0"] = true;
	regs["$r1"] = true;
	regs["$r2"] = true;
	regs["$r3"] = true;
	regs["$r4"] = true;
	regs["$r5"] = true;
	regs["$r6"] = true;
	regs["$r7"] = true;
	regs["$r8"] = true;
	regs["$r9"] = true;
	regs["$r10"] = true;
	regs["$r11"] = true;
	regs["$r12"] = true;
	regs["$r13"] = true;
	regs["$r14"] = true;
	regs["$r15"] = true;
	regs["$zero"] = true;

	return regs.count(reg_str) > 0;
}


bool ASMParser::valid_instruction(std::string ins_str) {
	return get_category(ins_str) != nullptr;
}

void ASMParser::add_category(std::unique_ptr<InsCategory> ins_cat) {
	poper_table.add_category(std::move(ins_cat));
}

std::vector<ParserNode *> ASMParser::parse(std::vector<TokenLine *> tokens) {
	size_t current_line = 0;
	size_t total_lines = tokens.size();

	std::vector<ParserNode *> nodes;
	for(int i = 0; i < tokens.size(); i++){
		// Get first token
		TokenLine *tok_line = tokens[i];

		// Ensure the token is an Operator.
		if (dynamic_cast<OperToken *>(tok_line->get_tokens()[0]) == nullptr) {

			// Bad grammer
			 std::vector<ParserNode *> error;
			 std::cout << "ERROR Parsing" << std::endl;
			 return error;
		} else {

			InsCategory *cat = poper_table.get_category(tok_line->get_tokens()[0]->get_lexeme());
			// TODO Ugly work-around to issue with polymorphism.
			
			ParserNode *node = nullptr;
			//node = parse_line(tok_line, cat, i);
			if (dynamic_cast<RCategory *>(cat) != nullptr) {
				node = parse_line(tok_line, dynamic_cast<RCategory *>(cat), i);
			} else if (dynamic_cast<ICategory *>(cat) != nullptr) {
				node = parse_line(tok_line, dynamic_cast<ICategory *>(cat), i);
			} else if (dynamic_cast<JCategory *>(cat) != nullptr){
				node = parse_line(tok_line, dynamic_cast<JCategory *>(cat), i);
			} else {
				std::cout << "ERROR: No known category type" << std::endl;
			}

			nodes.push_back(node);
		}
	}

	return nodes;
}

int extract_register_number(std::string lexeme) {
	if (lexeme.size() <= 0) {
		return -1;
	}
	if (lexeme[0] != '$') {
		return -1;
	}

	// find starting position of digit
	int index = 0;
	while(lexeme[index] < '0' || lexeme[index] > '9') {
		index++;
	}
	// found starting point of digits
	int starting_digit_index = index;
	std::stringstream ss;
	while(lexeme[index] != '\0') {
		ss << lexeme[index];
		index++;
	}

	std::cout << ss.str() << std::endl;

	return stoi(ss.str());
}

ParserNode *ASMParser::parse_line(TokenLine * token_line, RCategory* ins_cat, size_t line_position) {
	std::cout << "R-Type" << std::endl;
	std::vector<Token *> toks = token_line->get_tokens();

	std::cout << toks.size() << std::endl;

	Token * oper = toks[0];
	Token * r1 = toks[1];
	Token * r2 = toks[2];
	Token * dt = toks[3];

	RNode * ins_node = new RNode();
	ins_node->set_node_type(oper->get_lexeme());

	ParserNode::Register reg_1;
	reg_1.reg = extract_register_number(r1->get_lexeme());
	ParserNode::Register reg_2;
	reg_2.reg = extract_register_number(r2->get_lexeme());
	ParserNode::Register dst;
	dst.reg = extract_register_number(dt->get_lexeme());

	ins_node->src_one = reg_1;
	ins_node->src_two = reg_2;
	ins_node->dst = dst;

	std::cout << "Made rnode" << std::endl;

	return ins_node;
}

ParserNode *ASMParser::parse_line(TokenLine * token_line, ICategory* ins_cat, size_t line_position) {

	std::cout << "I-Type" << std::endl;
	std::vector<Token *> toks = token_line->get_tokens();

	std::cout << "Size of Token: " << toks.size() << std::endl;

	Token * oper = toks[0];
	Token * r1 = toks[1];
	Token * r2 = toks[2];
	Token * c = toks[3];

	INode * ins_node = new INode();
	ins_node->set_node_type(oper->get_lexeme());

	ParserNode::Register reg_1;
	reg_1.reg = extract_register_number(r1->get_lexeme());
	ParserNode::Register reg_2;
	reg_2.reg = extract_register_number(r2->get_lexeme());
	ParserNode::Constant constant;
	constant.constant = stoi(c->get_lexeme());

	ins_node->reg_one = reg_1;
	ins_node->reg_two = reg_2;
	ins_node->constant = constant;

	std::cout << "Made inode" << std::endl;

	return ins_node;
}

ParserNode *ASMParser::parse_line(TokenLine * token_line, JCategory* ins_cat, size_t line_position) {
	std::cout << "J-Type" << std::endl;
	std::vector<Token *> toks = token_line->get_tokens();

	Token * oper = toks[0];
	Token * c = toks[1];

	JNode * ins_node = new JNode();
	ins_node->set_node_type(oper->get_lexeme());

	ParserNode::Constant constant;
	constant.constant = stoi(c->get_lexeme());

	ins_node->constant = constant;

	return ins_node;

}

ParserNode *ASMParser::parse_line(TokenLine * token_line, InsCategory* ins_cat, size_t line_position) {
	std::cout << "Basic Type" << std::endl;

	return nullptr;

}

