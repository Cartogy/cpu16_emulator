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

class TokenLineTest : public ::testing::Test {
	protected:
		TokenLine tk_line;
};

TEST_F(TokenLineTest, TokenizeLineSingle) {
	std::string test_source_one = "add $r0 $r1 $r2";

	OperToken add = OperToken(0, "add");
	RegToken r0 = RegToken(4, "$r0");
	RegToken r1 = RegToken(8, "$r1");
	RegToken r2 = RegToken(12, "$r2");

	TokenLine tok_line;

	size_t next_index = tok_line.tokenize_line(0, test_source_one);

	// Ensure no errors
	EXPECT_EQ(0, tok_line.get_errors().size());
	// Ensure the next index is correct.
	EXPECT_EQ(15, next_index);

	// Test correct tokens.

	std::vector<Token *> tokens = tok_line.get_tokens();
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

TEST_F(TokenLineTest, TokenizeLineMultiple) {
	std::string test_source_one = "add $r0 $r1 $r2\nsub $r0 $r0 $r1";

	TokenLine tok_line_one;
	TokenLine tok_line_two;

	size_t next_index = tok_line_one.tokenize_line(0, test_source_one);
	EXPECT_EQ(15, next_index);
	next_index = tok_line_two.tokenize_line(16, test_source_one);
	EXPECT_EQ(31, next_index);
}

TEST(TokenizerTest, TokenizeSource) {
	std::string test_source = "add $r0 $r1 $r2\nsub $r0 $r0 $r1\naddi $r0 $r1 14\nmul $r0 $r3 $r3";

	std::vector<TokenLine *> tok_source = tokenize_source(test_source);
	std::cout << tok_source.size();

	ASSERT_EQ(4, tok_source.size());
}

TEST(TokenizerTest, TokenizeSourceCheck) {
	std::string test_source = "add $r0 $r1 $r2\nsub $r0 $r0 $r1\ndiv $r0 $r1 $r2\nmul $r0 $r3 $r3";
	std::vector<TokenLine *> tok_source = tokenize_source(test_source);

	// expected lexemes

	for(int i = 0; i < tok_source.size(); i++) {
		TokenLine *tok_line = tok_source[i];
		std::vector<Token *> tokens = tok_line->get_tokens();
		// Verify it is the correct token.
		ASSERT_FALSE(dynamic_cast<OperToken *>(tokens[0]) == nullptr);
		ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[1]) == nullptr);
		ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[2]) == nullptr);
		ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[3]) == nullptr);

		// Verify it is the expected token.
	}
}

class TokenizerObjTest : public ::testing::Test {
	protected:
		std::string file_name = "test_asm.asm";
		Tokenizer tokenizer;
};

TEST_F(TokenizerObjTest, TokenizeFileAllTokens) {
	tokenizer.tokenize_file(file_name);

	EXPECT_EQ(4, tokenizer.get_tokens().size());
}

TEST_F(TokenizerObjTest, TokenizeFileCorrectTokens) {
	tokenizer.tokenize_file(file_name);	

	std::vector<TokenLine *> token_lines = tokenizer.get_tokens();

	ASSERT_EQ(4, token_lines.size());

	// First Line
	TokenLine *first_line = token_lines[0];

	//// Errors
	std::vector<ErrorToken *> errors = first_line->get_errors();
	ASSERT_EQ(0, errors.size());

	//// Tokens
	std::vector<Token *> tokens = first_line->get_tokens();
	ASSERT_EQ(4, tokens.size());

	////// Oper Token
	ASSERT_FALSE(dynamic_cast<OperToken *>(tokens[0]) == nullptr);
	ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[1]) == nullptr);
	ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[2]) == nullptr);
	ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[3]) == nullptr);



	TokenLine *second_line = token_lines[1];

	//// Errors
	errors = second_line->get_errors();
	ASSERT_EQ(0, errors.size());

	//// Tokens
	tokens = second_line->get_tokens();
	ASSERT_EQ(4, tokens.size());

	////// Oper Token
	ASSERT_FALSE(dynamic_cast<OperToken *>(tokens[0]) == nullptr);
	ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[1]) == nullptr);
	ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[2]) == nullptr);
	ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[3]) == nullptr);

	TokenLine *third_line = token_lines[2];
	
	//// Errors
	errors = third_line->get_errors();
	ASSERT_EQ(0, errors.size());

	//// Tokens
	tokens = third_line->get_tokens();
	ASSERT_EQ(4, tokens.size());

	////// Oper Token
	ASSERT_FALSE(dynamic_cast<OperToken *>(tokens[0]) == nullptr);
	ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[1]) == nullptr);
	ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[2]) == nullptr);
	ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[3]) == nullptr);

	TokenLine *fourth_line = token_lines[3];
	
	//// Errors
	errors = fourth_line->get_errors();
	ASSERT_EQ(0, errors.size());

	//// Tokens
	tokens = fourth_line->get_tokens();
	ASSERT_EQ(4, tokens.size());

	////// Oper Token
	ASSERT_FALSE(dynamic_cast<OperToken *>(tokens[0]) == nullptr);
	ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[1]) == nullptr);
	ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[2]) == nullptr);
	ASSERT_FALSE(dynamic_cast<RegToken *>(tokens[3]) == nullptr);
}
