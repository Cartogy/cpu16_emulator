#include <iostream>
#include <vector>

/* Responsible to store all the valid instruction names to be checked in the Parser via the POperTable */


class InsCategory{
	private:
		std::vector<std::string> instructions;
	public:
		InsCategory();
		~InsCategory();
		const std::vector<std::string> get_instructions();
		void add_instruction(std::string ins);

		virtual void category_info() = 0;
};

class RCategory : public InsCategory {
	public:
		RCategory();

		void category_info(); 

};

class ICategory : public InsCategory {
	public:
		ICategory();

		void category_info();
};

class JCategory : public InsCategory {
	public:
		JCategory();
		void category_info();
};
