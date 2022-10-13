#include "operator.hpp"

class OpAdd: public Operator {
public:
	OpAdd(uint16_t p_id) : Operator(p_id) {
	}
	void func(uint16_t* pc, uint16_t *regs, Memory& mem) {
		std::cout << "ADD" << std::endl;
	}
};

class OpSub: public Operator {
public:

	OpSub(uint16_t p_id) : Operator(p_id) {}

	void func(uint16_t* pc, uint16_t *regs, Memory& mem) {
		std::cout << "Sub" << std::endl;
	}
};
