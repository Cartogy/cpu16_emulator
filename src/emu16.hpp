#include "Emulator/emulator.hpp"
#include "emu_operator.hpp"

class Emulator16 : public Emulator {
	public:
		Emulator16(size_t total_ops);
		void instruction_set();
};
