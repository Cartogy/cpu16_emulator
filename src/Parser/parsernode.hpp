#ifndef PARSER_NODE
#define PARSER_NODE

#include <vector>
#include <iostream>
#include <map>

struct ParserNode {
	private:
		std::string node_type;
	public:
		ParserNode();
		// ensures that we can call delete on the classes.
		virtual ~ParserNode() = default;
		struct Register{
			size_t reg;
		};

		struct Constant {
			size_t constant;
		};
		void set_node_type(std::string n_type);
		std::string get_node_type();

		virtual void node_information();
		virtual uint16_t encoding(uint16_t op_code) = 0;

};

struct RNode : ParserNode {
		RNode();
		Register src_one;
		Register src_two;
		Register dst;
		void node_information();
		uint16_t encoding(uint16_t op_code);
};

struct INode : ParserNode {
	INode();
		Register reg_one;
		Register reg_two;
		Constant constant;

		void node_information();
		uint16_t encoding(uint16_t op_code);
};

struct JNode : ParserNode {
	JNode();
		Constant constant;

		void node_information();
		uint16_t encoding(uint16_t op_code);
};

#endif
