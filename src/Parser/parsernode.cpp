#include "parsernode.hpp"
#include <iostream>

ParserNode::ParserNode() {
}

void ParserNode::set_node_type(std::string n_type) {
	node_type = n_type;
}

std::string ParserNode::get_node_type() {
	return node_type;
}

void ParserNode::node_information() { }

RNode::RNode() { 
}
INode::INode() {
}
JNode::JNode() {
}

void RNode::node_information() { 
	std::cout << "RNode" << std::endl;
}

uint16_t RNode::encoding(uint16_t op_code) {

	uint16_t reg_one = src_one.reg;
	uint16_t reg_two = src_two.reg;

	uint16_t ins_code = (op_code << 12) | (reg_one << 8) | (reg_two << 4) | dst.reg;

	return ins_code;

}

uint16_t INode::encoding(uint16_t op_code) {

	uint16_t ins_code = (op_code << 12) | (reg_one.reg << 8) | (reg_two.reg << 4) | constant.constant;

	return ins_code;

}

uint16_t JNode::encoding(uint16_t op_code) {

	uint16_t ins_code = (op_code << 12) | constant.constant;

	return ins_code;

}

void INode::node_information() { 
	std::cout << "INode" << std::endl;
}

void JNode::node_information() { 
	std::cout << "JNode" << std::endl;
}


