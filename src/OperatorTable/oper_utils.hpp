#ifndef OPER_UTILS
#define OPER_UTILS

#include <iostream>
// R-Instruction Extraction.
uint16_t r_src_one(uint16_t ins); 

uint16_t r_src_two(uint16_t ins); 

uint16_t r_dst(uint16_t ins); 

uint16_t i_reg_one(uint16_t ins); 

uint16_t i_reg_two(uint16_t ins); 

uint16_t i_imm(uint16_t ins); 

uint16_t j_addr(uint16_t ins); 
#endif
