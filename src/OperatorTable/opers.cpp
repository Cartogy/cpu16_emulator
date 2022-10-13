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

class OpMul : public Operator {
	public:
		OpMul(uint16_t p_id) : Operator(p_id) {}

		void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {
			uint16_t reg_1 = r_src_one(ins);
			uint16_t reg_2 = r_src_two(ins);
			uint16_t dst = r_dst(ins);

			regs[dst] = regs[reg_1] * regs[reg_2];

			std::cout << "Mul" << std::endl;
		}
};

class OpDiv : public Operator {
	public:
		OpDiv(uint16_t p_id) : Operator(p_id) {}

		void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {
			uint16_t reg_1 = r_src_one(ins);
			uint16_t reg_2 = r_src_two(ins);
			uint16_t dst = r_dst(ins);

			regs[dst] = regs[reg_1] / regs[reg_2];

			std::cout << "Div" << std::endl;
		}
};

class OpLoad : public Operator {
	public:
		OpLoad(uint16_t p_id) : Operator(p_id) {}

		void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {

			std::cout << "Load" << std::endl;
			std::cout << "Not yet implemented." << std::endl;
		}
};

class OpStore : public Operator {
	public:
		OpStore(uint16_t p_id) : Operator(p_id) {}

		void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {

			std::cout << "Store" << std::endl;
			std::cout << "Not yet implemented." << std::endl;
		}
};

class OpAddI : public Operator {
	public:
		OpAddI(uint16_t p_id) : Operator(p_id) {}

		void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {

			std::cout << "AddI" << std::endl;
			std::cout << "Not yet implemented." << std::endl;
		}
};

class OpSubI : public Operator {
	public:
		OpSubI(uint16_t p_id) : Operator(p_id) {}

		void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {

			std::cout << "SubI" << std::endl;
			std::cout << "Not yet implemented." << std::endl;
		}
};

class OpBranchEqual : public Operator {
	public:
		OpBranchEqual(uint16_t p_id) : Operator(p_id) {}

		void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {

			std::cout << "BranchEqual" << std::endl;
			std::cout << "Not yet implemented." << std::endl;
		}
};

class OpJmp : public Operator {
	public:
		OpJmp(uint16_t p_id) : Operator(p_id) {}

		void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {

			std::cout << "Jump" << std::endl;
			std::cout << "Not yet implemented." << std::endl;
		}
};
