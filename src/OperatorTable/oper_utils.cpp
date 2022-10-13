
#include <iostream>
// R-Instruction Extraction.
uint16_t r_src_one(uint16_t ins) {
	return ((15 << 8) & ins) >> 8;
}

uint16_t r_src_two(uint16_t ins) {
	return ((15 << 4) & ins) >> 4;
}

uint16_t r_dst(uint16_t ins) {
	return 15 & ins;
}

uint16_t i_reg_one(uint16_t ins) {
	return ((15 << 8) & ins) >> 8;
}

uint16_t i_reg_two(uint16_t ins) {
	return ((15 << 4) & ins) >> 4;
}

uint16_t i_imm(uint16_t ins) {
	return 15 & ins;
}

uint16_t j_addr(uint16_t ins) {
	// remove the opcode, and have the first four bits become 0: 0000 1111 1111 1111 => 1111 1111 1111 0000
	uint16_t addr = (ins << 4);
	// shift the bit back to only contain the first 12 bits
	// 1111 1111 1111 0000 => 0000 1111 1111 1111
	addr = addr >> 4;

	return addr;
}
