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

TEST_F(ParserTokenTest, CategoryTestRNode) {
	std::vector<TokenLine *> test_one = tokenize_source(source_one);

	std::vector<ParserNode *> parsed_nodes;
	parsed_nodes = asm_parser.parse(test_one);


	ASSERT_EQ(1 , parsed_nodes.size());


	// Test RNode
	ASSERT_FALSE(dynamic_cast<RNode *>(parsed_nodes[0]) == nullptr);
	RNode * r_node = dynamic_cast<RNode *>(parsed_nodes[0]);
	EXPECT_STREQ("add", parsed_nodes[0]->get_node_type().c_str());
	
	ParserNode::Register reg_1 = r_node->src_one;
	ParserNode::Register reg_2 = r_node->src_two;
	ParserNode::Register reg_3 = r_node->dst;

	EXPECT_EQ(0, reg_1.reg);
	EXPECT_EQ(0, reg_2.reg);
	EXPECT_EQ(1, reg_3.reg);

	
}

TEST_F(ParserTokenTest, CategoryTestINode) {
	std::vector<TokenLine *> test_one = tokenize_source(source_two);

	std::vector<ParserNode *> parsed_nodes;
	parsed_nodes = asm_parser.parse(test_one);


	ASSERT_EQ(1 , parsed_nodes.size());


	// Test RNode
	ASSERT_FALSE(dynamic_cast<INode *>(parsed_nodes[0]) == nullptr);
	INode * i_node = dynamic_cast<INode *>(parsed_nodes[0]);
	EXPECT_STREQ("addi", parsed_nodes[0]->get_node_type().c_str());
	
	ParserNode::Register reg_1 = i_node->reg_one;
	ParserNode::Register reg_2 = i_node->reg_two;
	ParserNode::Constant c = i_node->constant;

	EXPECT_EQ(0, reg_1.reg);
	EXPECT_EQ(0, reg_2.reg);
	EXPECT_EQ(5, c.constant);

}

TEST_F(ParserTokenTest, CategoryTestJNode) {
	std::vector<TokenLine *> test_one = tokenize_source(source_three);

	std::vector<ParserNode *> parsed_nodes;
	parsed_nodes = asm_parser.parse(test_one);


	ASSERT_EQ(1 , parsed_nodes.size());


	// Test JNode
	ASSERT_FALSE(dynamic_cast<JNode *>(parsed_nodes[0]) == nullptr);
	JNode * j_node = dynamic_cast<JNode *>(parsed_nodes[0]);
	EXPECT_STREQ("jmp", parsed_nodes[0]->get_node_type().c_str());
	
	ParserNode::Constant c = j_node->constant;

	EXPECT_EQ(10, c.constant);

}

TEST_F(ParserTokenTest, MultipleTokenLines) {
	std::vector<TokenLine *> test_one = tokenize_source(multiple_line);

	std::vector<ParserNode *> parsed_nodes;
	parsed_nodes = asm_parser.parse(test_one);

	ASSERT_EQ(3, parsed_nodes.size());

	ParserNode* node_1 = parsed_nodes[0];
	ParserNode* node_2 = parsed_nodes[1];
	ParserNode* node_3 = parsed_nodes[2];

	// Check RNode
	ASSERT_FALSE(dynamic_cast<RNode *>(node_1) == nullptr);
	RNode * r_node = dynamic_cast<RNode *>(node_1);
	EXPECT_STREQ("add", node_1->get_node_type().c_str());
	
	ParserNode::Register reg_1 = r_node->src_one;
	ParserNode::Register reg_2 = r_node->src_two;
	ParserNode::Register reg_3 = r_node->dst;

	EXPECT_EQ(0, reg_1.reg);
	EXPECT_EQ(0, reg_2.reg);
	EXPECT_EQ(1, reg_3.reg);

	// Check INode
	ASSERT_FALSE(dynamic_cast<INode *>(node_2) == nullptr);
	INode * i_node = dynamic_cast<INode *>(node_2);
	EXPECT_STREQ("addi", node_2->get_node_type().c_str());
	
	reg_1 = i_node->reg_one;
	reg_2 = i_node->reg_two;
	ParserNode::Constant cst = i_node->constant;

	EXPECT_EQ(0, reg_1.reg);
	EXPECT_EQ(0, reg_2.reg);
	EXPECT_EQ(5, cst.constant);


	// Check JNode
	ASSERT_FALSE(dynamic_cast<JNode *>(node_3) == nullptr);
	JNode * j_node = dynamic_cast<JNode *>(node_3);
	EXPECT_STREQ("jmp", node_3->get_node_type().c_str());
	
	ParserNode::Constant c = j_node->constant;

	EXPECT_EQ(10, c.constant);
}
