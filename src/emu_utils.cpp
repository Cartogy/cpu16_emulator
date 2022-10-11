#include "emu_utils.hpp"

uint16_t create_r_ins(uint8_t op, uint8_t src_1, uint8_t src_2, uint8_t dst){
	uint16_t bin_value = 0;
	bin_value = (op << 12) | (src_1 << 8) | (src_2 << 4) | dst;

	return bin_value;
}

