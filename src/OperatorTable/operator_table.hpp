#include <memory>
#include <vector>
#include "operator.hpp"
#define MAX_OPERATORS_POSSIBLE 100


class OperatorTable {
	private:
		// Using a unique ptr to store the polymorphic objects.
		// We could have done: vector<Operator *>, but we want to document that the OperatorTable owns these Operators.
		std::vector<std::unique_ptr<Operator>> operators;
		int limit;
	public:
		OperatorTable(int p_limit);
		void add_operator(std::unique_ptr<Operator> op);
		Operator* get_operator(int id);
};
