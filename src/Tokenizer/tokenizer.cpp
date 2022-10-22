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

void Token::token_information() {
	std::cout << "Basic Token" << std::endl;
}

RegToken::RegToken(size_t p_line, std::string lex) : Token(p_line,lex) {
}

OperToken::OperToken(size_t p_line, std::string lex) : Token(p_line,lex) {
}

NumberToken::NumberToken(size_t p_line, std::string lex) :Token(p_line, lex) {
}

ErrorToken::ErrorToken(size_t p_line, std::string lex) : Token(p_line,lex) {
}

ErrorToken::~ErrorToken() {
}

void ErrorToken::set_error_message(std::string msg) {
	error_msg = msg;
}

std::string ErrorToken::get_error_message() {
	return error_msg;
}

/* Tokenizer */
std::pair<Token *,size_t> tokenize_lexeme(size_t src_index, std::string source) {
	size_t end;
	size_t index = src_index;

	// Find the end of the word.
	while(source[index] != ' ' && source[index] != '\n' && source[index] != EOF && source[index] != '\0') {
		index++;
	}
	end = index;
	std::stringstream lexeme_stream;
	
	// focus on the word
	for(int i = src_index; i < end; i++) {
		lexeme_stream << source[i];
	}

	std::string lexeme = lexeme_stream.str();

	std::pair<Token *, size_t> tok_and_next_line;
	tok_and_next_line.second = end;

	// check if lexeme is a register
	if (lexeme[0] == '$') {
		RegToken *reg_tok = new RegToken(src_index, lexeme);
		tok_and_next_line.first = reg_tok;

		return tok_and_next_line;
	}

	// Check if lexeme is a number
	if (lexeme[0] >= '0' && lexeme[0] <= '9') {
		for(int i = 0; i < lexeme.size(); i++) {
			if (lexeme[i] < '0' || lexeme[i] > '9') {
				ErrorToken *err_token = new ErrorToken(src_index, lexeme);
				err_token->set_error_message("Invalid lexeme/word: Expected a numerical lexeme");

				tok_and_next_line.first = err_token;
				return tok_and_next_line;
			}
		}

		NumberToken *num_tok = new NumberToken(src_index, lexeme);
		tok_and_next_line.first = num_tok;

		return tok_and_next_line;

	}

	// CHeck only letters are in the lexeme
	for(int i = 0; i < lexeme.size(); i++) {
		// A non-letter character is in the lexeme
		if ((lexeme[i] >= 'a' && lexeme[i] <= 'z') == false) {
			ErrorToken *err_token = new ErrorToken(src_index, lexeme);
			err_token->set_error_message("Invalid lexeme/word");

			tok_and_next_line.first = err_token;
			return tok_and_next_line;
		}

	}

	OperToken *oper_tok = new OperToken(src_index, lexeme);
	tok_and_next_line.first = oper_tok;
	return tok_and_next_line;
}

TokenLine::TokenLine() {}

void TokenLine::set_line(size_t p_line) {
	line = p_line;
}

void TokenLine::add_token(ErrorToken * error) {
	errors.push_back(error);
}

void TokenLine::add_token(Token * token) {
	tokens.push_back(token);
}

std::vector<Token *> TokenLine::get_tokens() {
	return tokens;
}

std::vector<ErrorToken *> TokenLine::get_errors() {
	return errors;
}

size_t TokenLine::tokenize_line(size_t src_index, std::string source) {
	int index = src_index;

	while(source[index] != '\n' && source[index] != EOF && source[index] != '\0') {
		// Acquire specific lexeme token.
		std::pair<Token *, size_t> toks = tokenize_lexeme(index, source);

		// Push corresponding token.
		add_token(toks.first);

		// Store the next index to check.
		index = toks.second;
		// Advance to the next word
		if (source[index] == ' ') {
			index++;
		}
	}
	// Store the end point of the line. (i.e., the index stand on either '\n' or EOF or '\0'

	return index;
}

std::vector<TokenLine *> tokenize_source(std::string source) {
	size_t start = 0;
	size_t index = start;
	size_t current_line = 0;

	std::vector<TokenLine *> src_tokens;
	while(source[index] != EOF && source[index] != '\0') {
		TokenLine *line_tok = new TokenLine();	
		line_tok->set_line(current_line);

		// index is points to the end of the line.
		index = line_tok->tokenize_line(index, source);
		src_tokens.push_back(line_tok);

		if (source[index] == '\n') {
			index++;
		}
	}

	return src_tokens;
}
