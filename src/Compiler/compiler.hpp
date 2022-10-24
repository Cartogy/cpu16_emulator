#include "../Tokenizer/tokenizer.hpp"
#include "../Parser/asmparser.hpp"
#include "../MachineCodeGenerator/machinecodegenerator.hpp"

class Compiler {
	private:
		Tokenizer tokenizer;
		ASMParser parser;
		MachineCodeGenerator machine_code_gen;
	public:
		Compiler();
		~Compiler();

		std::vector<uint16_t> compile_source(std::string source);
		std::vector<uint16_t> compile_file(std::string file);
};
