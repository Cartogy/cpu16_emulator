#include <map>
#include <vector>
#include <memory>

#include "../Parser/parsernode.hpp"

class MachineCodeGenerator {
	private:
		std::map<std::string, uint16_t> instruction_table;

	public:
		MachineCodeGenerator();
		~MachineCodeGenerator();


		std::vector<uint16_t> generate_code(std::vector<ParserNode *> nodes);

};
