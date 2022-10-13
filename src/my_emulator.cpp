#include "emulator.hpp"
#include "OperatorTable/opers.cpp"

class Emulator16 : public Emulator {
	public:
		Emulator16(uint16_t total_ops) : Emulator(total_ops) {}
		void instruction_set() {
			OpAdd add(4);
			OpSub sub(5);
			add_operator(&add);
			add_operator(&sub);
		}
};
