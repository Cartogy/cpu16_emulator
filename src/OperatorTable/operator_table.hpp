#include <vector>
#include "operator.hpp"
#define MAX_OPERATORS_POSSIBLE 100


class OperatorTable {
	private:
		// Use a reference becase the array would try and initialize the objects.
		// But due to it being abstract, there is no possible instance of the object.
		std::vector<Operator*> operators;
		int limit;
	public:
		OperatorTable(int p_limit);
		void add_operator(Operator* op);
		Operator* get_operator(int id);
};
