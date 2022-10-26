#include <sstream>
#include <gtest/gtest.h>
#include "Compiler/compiler.hpp"
#include "emu_utils.hpp"

class CompilerTest : public ::testing::Test { 
	protected:
		Compiler compiler;
		uint16_t add_ins;
		uint16_t sub_ins;
		uint16_t addi_ins;
		uint16_t jmp_ins;

		std::string add_src;
		std::string sub_src;
		std::string addi_src;
		std::string jmp_src;

		void SetUp() override {
			add_ins = create_r_ins(4, 0, 0, 1);
			sub_ins = create_r_ins(5, 1, 2, 3);
			addi_ins = create_i_ins(10, 0, 1, 9);
			jmp_ins = create_j_ins(2,15);

			add_src = "add $r0 $r0 $r1";
			sub_src = "sub $r1 $r2 $r3";
			addi_src = "addi $r0 $r1 9";
			jmp_src = "jmp 15";
		}
};

TEST_F(CompilerTest, SingleInstruction) {
	std::vector<uint16_t> code_list;
	code_list = compiler.compile_source(add_src);
	ASSERT_EQ(1, code_list.size());
	EXPECT_EQ(add_ins,code_list[0]) << "Incosistence Instruction for add" << std::endl;

	code_list = compiler.compile_source(sub_src);
	ASSERT_EQ(1, code_list.size());
	EXPECT_EQ(sub_ins, code_list[0]) << "Inconsistency instruction for sub" << std::endl;

	code_list = compiler.compile_source(addi_src);
	ASSERT_EQ(1, code_list.size());
	EXPECT_EQ(addi_ins,code_list[0]) << "Inconsistent instruction for addi" << std::endl;

	code_list = compiler.compile_source(jmp_src);
	ASSERT_EQ(1, code_list.size());
	EXPECT_EQ(jmp_ins,code_list[0]) << "Inconsistent instruction for jmp" << std::endl;
}

TEST_F(CompilerTest, MultipleInstructions) {
	std::vector<uint16_t> code_list;
	code_list.push_back(add_ins);
	code_list.push_back(sub_ins);
	code_list.push_back(addi_ins);
	code_list.push_back(jmp_ins);

	std::stringstream src_stream;
	src_stream << add_src << '\n' << sub_src << '\n' << addi_src << '\n' << jmp_src;

	std::vector<uint16_t> actual_code_list = compiler.compile_source(src_stream.str());

	// Ensure the appropriate elements are contained.
	ASSERT_EQ(4, actual_code_list.size());
	ASSERT_EQ(code_list.size(), actual_code_list.size());

	for(int i = 0; i < actual_code_list.size(); i++) {
		EXPECT_EQ(code_list[i], actual_code_list[i]);
	}
}
