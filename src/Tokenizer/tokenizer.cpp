#include "tokenizer.hpp"
#include <sstream>

/* Token */
Token::Token(size_t p_line, std::string lex) {
	line_position = p_line;
	lexeme = lex;
}

Token::~Token() {}

size_t Token::get_line_position() {
	return line_position;
}

std::string Token::get_lexeme() {
	return lexeme;
}

RegToken::RegToken(size_t p_line, std::string lex) : Token(p_line,lex) {
}

OperToken::OperToken(size_t p_line, std::string lex) : Token(p_line,lex) {
}

ErrorToken::ErrorToken(size_t p_line, std::string lex) : Token(p_line,lex) {
}

void ErrorToken::set_error_message(std::string msg) {
	error_msg = msg;
}

/* Tokenizer */
std::pair<Token *,size_t> tokenize_lexeme(size_t line_num, std::string source) {
	size_t end;
	size_t index = line_num;

	// Find the end of the word.
	while(source[index] != ' ' && source[index] != '\n' && source[index] != EOF) {
		index++;
	}
	end = index;
	std::stringstream lexeme_stream;
	
	// focus on the word
	for(int i = line_num; i < end; i++) {
		lexeme_stream << source[i];
	}

	std::string lexeme = lexeme_stream.str();

	std::pair<Token *, size_t> tok_and_next_line;
	tok_and_next_line.second = end;

	// check if lexeme is a register
	if (lexeme[0] == '$') {
		RegToken *reg_tok = new RegToken(line_num, lexeme);
		tok_and_next_line.first = reg_tok;

		return tok_and_next_line;
	}

	// CHeck only letters are in the lexeme
	for(int i = 0; i < lexeme.size(); i++) {
		// A non-letter character is in the lexeme
		if ((lexeme[i] >= 'a' && lexeme[i] <= 'z') == false) {
			ErrorToken *err_token = new ErrorToken(line_num, lexeme);
			err_token->set_error_message("Invalid lexeme/word");

			tok_and_next_line.first = err_token;
			return tok_and_next_line;
		}
	}

	OperToken *oper_tok = new OperToken(line_num, lexeme);
	tok_and_next_line.first = oper_tok;
	return tok_and_next_line;
}
