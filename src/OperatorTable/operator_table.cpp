#include "operator_table.hpp"

OperatorTable::OperatorTable(int p_limit) {
	operators.reserve(p_limit);
	
	// Initialize the array.
	for(int i = 0; i < p_limit; i++) {
		operators.push_back(nullptr);
	}
}

void OperatorTable::add_operator(Operator &op) {
	uint16_t id = op.get_id();

	if (operators[id] == nullptr) {
		operators[id] = op;
	} else {
		std::cout << "Operator ID already occupied" << std::endl;
	}
}

Operator* OperatorTable::get_operator(int id) {
	return operators[id];
}

