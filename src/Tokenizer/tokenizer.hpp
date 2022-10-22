#include <iostream>
#include <vector>
#include <utility>

class Token {
	private:
		size_t line_position;
		std::string lexeme;
	public:
		Token(size_t p_line, std::string lex);
		~Token();
		std::string get_lexeme();
		size_t get_line_position();

		// By having the base class have a virtual function, we make it become polymorphic.
		virtual void token_information();
};

class RegToken : public Token {
	public:
		RegToken(size_t p_line, std::string lex);
};

class OperToken : public Token {
	public:
		OperToken(size_t p_line, std::string lex);
};

class NumberToken : public Token {
	public:
		NumberToken(size_t p_line, std::string lex);
};

class ErrorToken : public Token {
	private:
		std::string error_msg;
	public:
		ErrorToken(size_t p_line, std::string lex);
		~ErrorToken();

		void set_error_message(std::string msg);
		std::string get_error_message();
};

class TokenLine {
	private:
		std::vector<ErrorToken *> errors;
		std::vector<Token *> tokens;
		size_t line;

		void add_token(ErrorToken * error);
		void add_token(Token * token);
	public:
		TokenLine();

		size_t tokenize_line(size_t src_index, std::string source);
		void set_line(size_t p_line);

		std::vector<ErrorToken *> get_errors();
		std::vector<Token *> get_tokens();

};

std::pair<Token *, size_t> tokenize_lexeme(size_t src_index, std::string source);

std::vector<TokenLine *> tokenize_source(std::string);

class Tokenizer {
	public:
		void tokenize_file(std::string file_name);

};
