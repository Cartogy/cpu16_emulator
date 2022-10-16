#include <iostream>
#include <vector>

/* Responsible to store all the valid instruction names to be checked in the Parser via the POperTable */


class InsCategory{
	protected:
		std::vector<std::string> instructions;
	public:
		InsCategory();
		const std::vector<std::string> get_instructions();
};

class RCategory : public InsCategory {
	public:
		RCategory() {
			instructions.push_back("add");
			instructions.push_back("sub");
			instructions.push_back("div");
			instructions.push_back("mul");
		}

};

class ICategory : public InsCategory {
	public:
		ICategory() {
			instructions.push_back("load");
			instructions.push_back("store");
			instructions.push_back("addi");
			instructions.push_back("subi");
			instructions.push_back("bne");

		}

};

class JCategory : public InsCategory {
	public:
		JCategory() {
			instructions.push_back("jmp");
		}
};
