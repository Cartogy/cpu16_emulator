#include "emu_utils.hpp"

uint16_t create_r_ins(uint16_t op, uint16_t src_1, uint16_t src_2, uint16_t dst){
	uint16_t bin_value = 0;
	bin_value = (op << 12) | (src_1 << 8) | (src_2 << 4) | dst;

	return bin_value;
}

uint16_t create_i_ins(uint16_t op, uint16_t reg_one, uint16_t reg_two, uint16_t constant) {
	uint16_t bin_value = 0;

	bin_value = (op << 12) | (reg_one << 8) | (reg_two << 4) | constant;

	return bin_value;
}

uint16_t create_j_ins(uint16_t op, uint16_t constant) {
	uint16_t bin_value = 0;

	bin_value = (op << 12) | constant;

	return bin_value;
}
