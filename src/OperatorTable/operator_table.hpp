#include <memory>
#include <vector>
#include "Operator/operator.hpp"
#define MAX_OPERATORS_POSSIBLE 100


class OperatorTable {
	private:
		// Using a unique ptr to store the polymorphic objects.
		// We could have done: vector<Operator *>, but we want to document that the OperatorTable owns these Operators.
		std::vector<std::shared_ptr<Operator>> operators;
		int limit;
	public:
		OperatorTable();
		OperatorTable(int p_limit);
		void add_operator(std::shared_ptr<Operator> op);
		// We want to specify that whoever acquires the pointer to the operator is not meant to own it.
		// 
		Operator* get_operator(int id);
};
