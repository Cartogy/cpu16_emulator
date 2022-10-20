#include "Emulator/emulator.hpp"
#include "emu_operator.hpp"

class Emulator16 : public Emulator {
	public:
		Emulator16(uint16_t total_ops) : Emulator(total_ops) {
			instruction_set();
		}
		void instruction_set() {
			/* Ensure the operators are created in the heap. */
			// J-Type Instructions.
			std::unique_ptr<Operator> jmp(new OpJmp(2));

			// R-Type Instructions.
			std::unique_ptr<Operator> add(new OpAdd(4));
			std::unique_ptr<Operator> sub(new OpSub(5));
			std::unique_ptr<Operator> mul(new OpMul(6));
			std::unique_ptr<Operator> div(new OpDiv(7));

			// I-Type Instructions.
			std::unique_ptr<Operator> load(new OpLoad(8));
			std::unique_ptr<Operator> store(new OpStore(9));
			std::unique_ptr<Operator> addi(new OpAddI(10));
			std::unique_ptr<Operator> subi(new OpSubI(11));
			std::unique_ptr<Operator> branch_equal(new OpSubI(12));


			// Pass ownership of operators to the OperatorTable.
			add_operator(std::move(jmp));
			add_operator(std::move(add));
			add_operator(std::move(sub));
			add_operator(std::move(mul));
			add_operator(std::move(div));
			add_operator(std::move(load));
			add_operator(std::move(store));
			add_operator(std::move(addi));
			add_operator(std::move(subi));
			add_operator(std::move(branch_equal));
		}
};
