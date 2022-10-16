#include "popertable.hpp"



void PoperTable::add_category(std::unique_ptr<InsCategory> ins_cat) {
	for(std::string ins_name : (*ins_cat).get_instructions()) {
		ins_categories[ins_name] = std::move(ins_cat);
	}
}

InsCategory* PoperTable::get_category(std::string oper_name) {
	if (ins_categories.count(oper_name) == 0) {
		return nullptr;
	} else {
		return ins_categories[oper_name].get();
	}
}
