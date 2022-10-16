#include <vector>
#include <iostream>
#include <map>

struct ParserNode {
	public:
		struct Register{
			size_t reg;
		};

		struct Constant {
			size_t constant;
		};

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
