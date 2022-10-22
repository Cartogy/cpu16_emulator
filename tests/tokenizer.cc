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
	// TODO: Fix Core dump from the below line [x].
	std::pair<Token *, size_t> toks = tokenize_lexeme(0, test_source_one);

	/*TODO: Go over static_cast and dynamic_cast [ ] */
	ASSERT_FALSE(static_cast<OperToken *>(toks.first) == nullptr);
	EXPECT_STREQ(oper_tok_add.get_lexeme().c_str(), toks.first->get_lexeme().c_str());
	EXPECT_EQ(3, toks.second);

	// destroy the dynamically allocated Token
	delete toks.first;

	toks = tokenize_lexeme(0, test_source_two);

	ASSERT_FALSE(static_cast<OperToken *>(toks.first) == nullptr);
	EXPECT_STREQ(oper_tok_subi.get_lexeme().c_str(), toks.first->get_lexeme().c_str());
	EXPECT_EQ(4, toks.second);
	delete toks.first;

	toks = tokenize_lexeme(0, test_source_three);

}

TEST(TokenizerTest, LexemeReg) {
	std::string test_source_one = "add $r0 $r1 $r2";

	RegToken reg_one = RegToken(4,"$r0");
	RegToken reg_two = RegToken(8,"$r1");
	RegToken reg_three = RegToken(12,"$r2");

	std::pair<Token *, size_t> toks = tokenize_lexeme(4, test_source_one);

	ASSERT_FALSE(static_cast<RegToken *>(toks.first) == nullptr);
	EXPECT_STREQ(reg_one.get_lexeme().c_str(), toks.first->get_lexeme().c_str());
	EXPECT_EQ(7, toks.second);

	delete toks.first;

	toks = tokenize_lexeme(8, test_source_one);
	ASSERT_FALSE(static_cast<RegToken *>(toks.first) == nullptr);
	EXPECT_STREQ(reg_two.get_lexeme().c_str(), toks.first->get_lexeme().c_str());
	EXPECT_EQ(11, toks.second);

	delete toks.first;

	toks = tokenize_lexeme(12, test_source_one);
	ASSERT_FALSE(static_cast<RegToken *>(toks.first) == nullptr);
	EXPECT_STREQ(reg_three.get_lexeme().c_str(), toks.first->get_lexeme().c_str());
	EXPECT_EQ(15, toks.second);

	delete toks.first;
}

TEST(TokenizerTest, LexemeError) {
	std::string test_error_source = "add2d $r0";

	ErrorToken error_tok = ErrorToken(0, "add2d");
	error_tok.set_error_message("Invalid lexeme/word");

	std::pair<Token *, size_t> toks = tokenize_lexeme(0, test_error_source);

	ASSERT_FALSE(static_cast<ErrorToken *>(toks.first) == nullptr);
	EXPECT_STREQ(error_tok.get_lexeme().c_str(), toks.first->get_lexeme().c_str());
	EXPECT_STREQ(error_tok.get_error_message().c_str(), static_cast<ErrorToken *>(toks.first)->get_error_message().c_str());

	delete toks.first;

}

TEST(TokenizerTest, TokenizeLine) {
	std::string test_source_one = "add $r0 $r1 $r2";

	OperToken add = OperToken(0, "add");
	RegToken r0 = RegToken(4, "$r0");
	RegToken r1 = RegToken(8, "$r1");
	RegToken r2 = RegToken(12, "$r2");

	std::pair<std::vector<Token *>, std::pair<std::vector<ErrorToken *>, size_t>> tok_line;

	tok_line = tokenize_line(0, test_source_one);

	// Ensure no errors
	EXPECT_EQ(0, tok_line.second.first.size());
	// Ensure the next index is correct.
	EXPECT_EQ(15, tok_line.second.second);

	// Test correct tokens.

	std::vector<Token *> tokens = tok_line.first;
	// Test OperToken
	OperToken * oper_token = static_cast<OperToken *>(tokens[0]);
	//1) correct type of token.
	ASSERT_FALSE(oper_token == nullptr);
	EXPECT_STREQ(add.get_lexeme().c_str(), oper_token->get_lexeme().c_str());
	EXPECT_EQ(add.get_line_position(), oper_token->get_line_position());

	// Test Reg Token
	RegToken *reg_token_zero = static_cast<RegToken *>(tokens[1]);
	ASSERT_FALSE(reg_token_zero == nullptr);
	EXPECT_STREQ(r0.get_lexeme().c_str(), reg_token_zero->get_lexeme().c_str());
	EXPECT_EQ(r0.get_line_position(), reg_token_zero->get_line_position());

	// Test Reg Token
	RegToken *reg_token_one = static_cast<RegToken *>(tokens[2]);
	ASSERT_FALSE(reg_token_one == nullptr);
	EXPECT_STREQ(r1.get_lexeme().c_str(), reg_token_one->get_lexeme().c_str());
	EXPECT_EQ(r1.get_line_position(), reg_token_one->get_line_position());

	// Test Reg Token
	RegToken *reg_token_two = static_cast<RegToken *>(tokens[3]);
	ASSERT_FALSE(reg_token_two == nullptr);
	EXPECT_STREQ(r2.get_lexeme().c_str(), reg_token_two->get_lexeme().c_str());
	EXPECT_EQ(r2.get_line_position(), reg_token_two->get_line_position());
}
