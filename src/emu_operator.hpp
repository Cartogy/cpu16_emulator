#include <cstdint>

#include "OperatorTable/Operator/operator.hpp"
#include "OperatorTable/oper_utils.hpp"

class OpAdd: public Operator {
public:
	OpAdd(uint16_t p_id) : Operator(p_id) {
	}
	void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {
		uint16_t reg_1 = r_src_one(ins);
		uint16_t reg_2 = r_src_two(ins);
		uint16_t dst = r_dst(ins);

		regs[dst] = regs[reg_1] + regs[reg_2];
		std::cout << "Add" << std::endl;
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
			uint16_t dst_reg = i_reg_one(ins);
			uint16_t base_reg = i_reg_two(ins);
			uint16_t offset = i_imm(ins);

			uint16_t from_address = base_reg+offset;

			regs[dst_reg] = mem.load(from_address);

			std::cout << "Load" << std::endl;
		}
};

class OpStore : public Operator {
	public:
		OpStore(uint16_t p_id) : Operator(p_id) {}

		void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {
			uint16_t src_reg = i_reg_one(ins);
			uint16_t base_reg = i_reg_two(ins);
			uint16_t offset = i_imm(ins);

			uint16_t to_address = base_reg+offset;

			mem.store(to_address, regs[src_reg]);

			std::cout << "Store" << std::endl;
		}
};

class OpAddI : public Operator {
	public:
		OpAddI(uint16_t p_id) : Operator(p_id) {}

		void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {
			uint16_t src_one = i_reg_one(ins);
			uint16_t dst = i_reg_two(ins);
			uint16_t imm_val = i_imm(ins);

			regs[dst] = regs[src_one] + imm_val;

			std::cout << "AddI" << std::endl;
		}
};

class OpSubI : public Operator {
	public:
		OpSubI(uint16_t p_id) : Operator(p_id) {}

		void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {
			uint16_t src_one = i_reg_one(ins);
			uint16_t dst = i_reg_two(ins);
			uint16_t imm_val = i_imm(ins);

			regs[dst] = regs[src_one] - imm_val;

			std::cout << "SubI" << std::endl;
		}
};

// DUe to the immediate value only having 2^4 bits, the maximum branch must be 15 lines away from the original branching instruction.
class OpBranchEqual : public Operator {
	public:
		OpBranchEqual(uint16_t p_id) : Operator(p_id) {}

		void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {
			uint16_t reg_one = i_reg_one(ins);
			uint16_t reg_two = i_reg_two(ins);
			uint16_t offset = i_imm(ins);

			if (regs[reg_one] == regs[reg_two]) {
				*pc = *pc + offset;
			}

			std::cout << "BranchEqual" << std::endl;
		}
};

class OpJmp : public Operator {
	public:
		OpJmp(uint16_t p_id) : Operator(p_id) {}

		void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) {
			uint16_t jmp_address = j_addr(ins);
			// Use left-most bit to decide to add or subtract.
			// 2048 -> 0000 1000 0000 0000
			if (2048 & jmp_address) {
				// subtract from jmp address.
				// 0000 1000 0000 0000 XOR 1000 0000 0001 => 0000 0000 0000 0001
				jmp_address = jmp_address ^ 2048;
				*pc = *pc - jmp_address;
			} else {
				*pc = *pc + jmp_address;
			}

			std::cout << "Jump" << std::endl;
		}
};
