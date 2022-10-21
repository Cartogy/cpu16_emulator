#include <gtest/gtest.h>

#include "Tokenizer/tokenizer.hpp"

TEST(TokenizerTest, LexemeOper){
	std::string test_source_one = "add $r0 $r1 $r2";
	std::string test_source_two = "subi $r0 $r1 $r2";
	std::string test_source_three = "mul $r0 $r1 $r2";

	OperToken oper_tok_add = OperToken(0, "add");
	OperToken oper_tok_subi = OperToken(0, "subi");
	OperToken oper_tok_mul = OperToken(0, "mul");

	// Test add OperToken.
	// TODO: Fix Cor dump from the below line.
	std::pair<Token *, size_t> toks = tokenize_lexeme(0, test_source_one);

	/*TODO: Go over static_cast and dynamic_cast */
	//ASSERT_FALSE(static_cast<OperToken *>(toks.first) == nullptr);
//	EXPECT_STREQ(oper_tok_add.get_lexeme().c_str(), toks.first->get_lexeme().c_str());
}
