#include <iostream>

#ifndef EMU_UTILS
#define EMU_UTILS

uint16_t create_r_ins(uint16_t op, uint16_t src_1, uint16_t src_2, uint16_t dst);
uint16_t create_i_ins(uint16_t op, uint16_t reg_1, uint16_t reg_2, uint16_t constant);
uint16_t create_j_ins(uint16_t op, uint16_t c);

#endif
