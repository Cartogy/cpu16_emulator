#include <gtest/gtest.h>

#include "Parser/asmparser.hpp"

class ParserTokenTest : public ::testing::Test {
	protected:
		Tokenizer tokenizer;
		ASMParser asm_parser;

		std::string source_one = "add $r0 $r0 $r1";
		std::string source_two = "addi $r0 $r0 5";
		std::string source_three = "jmp 10";

		std::string multiple_line = "add $r0 $r0 $r1\naddi $r0 $r0 5\njmp 10";
};

TEST_F(ParserTokenTest, CategoryTest) {
	std::vector<TokenLine *> test_one = tokenize_source(source_one);

	std::vector<ParserNode *> parsed_nodes;
	parsed_nodes = asm_parser.parse(test_one);


	ASSERT_EQ(1 , parsed_nodes.size());


	EXPECT_STREQ("add", parsed_nodes[0]->get_node_type().c_str());
	ASSERT_FALSE(dynamic_cast<RNode *>(parsed_nodes[0]) == nullptr);
}
