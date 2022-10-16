#include <map>
#include <memory>
#include "InsCategory/inscategory.hpp"

/* Responsible for storing all valid instruction names and their respective categories */

class PoperTable {
	private:
		std::map<std::string, std::unique_ptr<InsCategory>> ins_categories;
	public:
		void add_category(std::unique_ptr<InsCategory> ins_cat);
		InsCategory* get_category(std::string oper_name);
};
