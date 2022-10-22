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

};

struct RNode : ParserNode {
	private:
		Register src_one;
		Register src_two;
		Register dst;
};

struct INode : ParserNode {
	private:
		Register reg_one;
		Register reg_two;
		Constant constant;
};

struct JNode : ParserNode {
	private:
		Constant constant;
};

struct ParsedLine {
	std::vector<ParserNode *> parsed_line;
};
