#include <map>
#include <memory>
#include "InsCategory/inscategory.hpp"

/* Responsible for storing all valid instruction names and their respective categories */

class PoperTable {
	private:
		// To store the categories as unique pointers.
		std::vector<std::unique_ptr<InsCategory>> categories_storage;
		//TODO: Refactor this to have many keys point to one value.
		// Due to the unique pointer, it returns the pointer of the categories.
		// In order to avoid any segmentation faults, the unique pointers are stored in the object.
		std::map<std::string, InsCategory *> ins_categories;
	public:
		PoperTable();
		~PoperTable();
		void add_category(std::unique_ptr<InsCategory> ins_cat);
		InsCategory* get_category(std::string oper_name);
};
