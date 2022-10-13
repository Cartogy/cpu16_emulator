#include <iostream>

#include "../Memory/memory.hpp"

class Operator {
	private:
		uint16_t id;
	public:
		Operator(uint16_t p_id);
		uint16_t get_id();
		virtual void func(uint16_t& pc, uint16_t *regs, Memory& mem) = 0;
};