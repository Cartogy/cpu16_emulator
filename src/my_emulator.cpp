#include "emulator.hpp"
#include "OperatorTable/opers.cpp"

class Emulator16 : public Emulator {
	public:
		Emulator16(uint16_t total_ops) : Emulator(total_ops) {
			instruction_set();
		}
		void instruction_set() {
			// Ensure the operators are created in the stack.
			std::unique_ptr<Operator> add(new OpAdd(4));
			std::unique_ptr<Operator> sub(new OpSub(5));

			// Pass ownership of operators to the OperatorTable.
			add_operator(std::move(add));
			add_operator(std::move(sub));
		}
};
