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
};

class RegToken : public Token {
	public:
		RegToken(size_t p_line, std::string lex);
};

class OperToken : public Token {
	public:
		OperToken(size_t p_line, std::string lex);
};

class ErrorToken : public Token {
	private:
		std::string error_msg;
	public:
		ErrorToken(size_t p_line, std::string lex);
		~ErrorToken();

		void set_error_message(std::string msg);
};

class Tokenizer {
	private:
		std::pair<Token *,size_t> tokenize_lexeme(size_t line_num, std::string source);
		std::pair<std::vector<Token *>,std::pair<std::vector<ErrorToken *>,size_t>> tokenize_line(size_t line_num, std::string source);
		std::pair<std::vector<Token *>,std::vector<ErrorToken *>> tokenize_source(std::string);

	public:
		void tokenize_file(std::string file_name);

};
