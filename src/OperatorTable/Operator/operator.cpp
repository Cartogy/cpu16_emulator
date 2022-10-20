#include "operator.hpp"

Operator::Operator(uint16_t p_id){
	id = p_id;
}

uint16_t Operator::get_id(){
	return id;
}
