/* use of references ideal as we don't pant to change the pointer when calling func */
#ifndef OPERATOR
#define OPERATOR
#include <iostream>

#include "../Memory/memory.hpp"

class Operator {
	private:
		uint16_t id;
	public:
		Operator(uint16_t p_id);
		uint16_t get_id();
		virtual void func(uint16_t* pc, uint16_t *regs, uint16_t ins, Memory& mem) = 0;
};
#endif
