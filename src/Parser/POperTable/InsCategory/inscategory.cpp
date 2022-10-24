#include "inscategory.hpp"

InsCategory::InsCategory() {

}

InsCategory::~InsCategory() { }

const std::vector<std::string> InsCategory::get_instructions() {
	return instructions;	
}

RCategory::RCategory() : InsCategory() {
			add_instruction("add");
			add_instruction("sub");
			add_instruction("div");
			add_instruction("mul");
}

void RCategory::category_info() {

}

ICategory::ICategory() : InsCategory(){
			add_instruction("load");
			add_instruction("store");
			add_instruction("addi");
			add_instruction("subi");
			add_instruction("bne");

}

void ICategory::category_info() {

}

JCategory::JCategory() : InsCategory(){
			add_instruction("jmp");
}

void JCategory::category_info() {

}

void InsCategory::add_instruction(std::string ins) {
	instructions.push_back(ins);
}
