#include "parsernode.hpp"
void ParserNode::set_node_type(std::string n_type) {
	node_type = n_type;
}

std::string ParserNode::get_node_type() {
	return node_type;
}

void ParserNode::node_information() { }
