#include "popertable.hpp"

PoperTable::PoperTable() {
	add_category(std::shared_ptr<RCategory>(new RCategory()));
	add_category(std::shared_ptr<ICategory>(new ICategory()));
	add_category(std::shared_ptr<JCategory>(new JCategory()));
}

PoperTable::~PoperTable() {
}

void PoperTable::add_category(std::shared_ptr<InsCategory> ins_cat) {
	for(std::string ins_name : (*ins_cat).get_instructions()) {
		ins_categories[ins_name] = ins_cat.get();
	}

	categories_storage.push_back(std::move(ins_cat));
}

InsCategory* PoperTable::get_category(std::string oper_name) {
	if (ins_categories.count(oper_name) == 0) {
		return nullptr;
	} else {
		return ins_categories[oper_name];
	}
}
