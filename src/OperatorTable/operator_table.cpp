#include "operator_table.hpp"
#include <memory>

OperatorTable::OperatorTable() {
}

OperatorTable::OperatorTable(int p_limit) {
	operators.reserve(p_limit);
	
	// Initialize the array.
	for(int i = 0; i < p_limit; i++) {
		operators.push_back(nullptr);
	}
}

void OperatorTable::add_operator(std::shared_ptr<Operator> op) {
	uint16_t id = op->get_id();

	if (operators[id] == nullptr) {
		// Have the array own the op object.
		operators[id] = op;
	} else {
		std::cout << "OperatorTable::Operator ID already occupied" << std::endl;
	}
}

Operator* OperatorTable::get_operator(int id) {
	// Pass the raw pointer.
	// Assumption: This pointer is not meant to be stored by the caller.
	if (operators.size() <= 0) {
		return nullptr;
	}

	return operators[id].get();
}

