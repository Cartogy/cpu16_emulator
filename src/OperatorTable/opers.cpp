#include "operator.hpp"
#include "oper_utils.hpp"
#include <cstdint>

class OpAdd: public Operator {
public:
	OpAdd(uint16_t p_id) : Operator(p_id) {
	}
	void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {
		uint16_t reg_1 = r_src_one(ins);
		uint16_t reg_2 = r_src_two(ins);
		uint16_t dst = r_dst(ins);

		regs[dst] = regs[reg_1] + regs[reg_2];
		std::cout << "ADD" << std::endl;
	}
};

class OpSub: public Operator {
public:

	OpSub(uint16_t p_id) : Operator(p_id) {}

	void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {
		uint16_t reg_1 = r_src_one(ins);
		uint16_t reg_2 = r_src_two(ins);
		uint16_t dst = r_dst(ins);

		regs[dst] = regs[reg_1] - regs[reg_2];

		std::cout << "Sub" << std::endl;
	}
};
