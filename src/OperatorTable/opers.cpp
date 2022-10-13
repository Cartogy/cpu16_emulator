#include "operator.hpp"

class OpAdd: public Operator {
public:
	void func(uint16_t& pc, uint16_t *regs, Memory& mem) {
		std::cout << "ADD" << std::endl;
	}
};

class OpSub: public Operator {
public:
	void func(uint16_t& pc, uint16_t *regs, Memory& mem) {
		std::cout << "Sub" << std::endl;
	}
};
