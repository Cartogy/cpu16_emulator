#include <vector>
#include <iostream>
#include <map>

struct ParserNode {
	private:
		std::string node_type;
	public:
		struct Register{
			size_t reg;
		};

		struct Constant {
			size_t constant;
		};
		void set_node_type(std::string n_type);
		std::string get_node_type();

		virtual void node_information();

};

struct RNode : ParserNode {
		Register src_one;
		Register src_two;
		Register dst;
};

struct INode : ParserNode {
		Register reg_one;
		Register reg_two;
		Constant constant;
};

struct JNode : ParserNode {
		Constant constant;
};

struct ParsedLine {
	std::vector<ParserNode *> parsed_line;
};
