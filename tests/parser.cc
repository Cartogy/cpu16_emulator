#include <gtest/gtest.h>
#include <memory>
#include "Parser/asmparser.hpp"

// InsCategory

class InsCategoryTest : public ::testing::Test {
	protected:
		RCategory r_cat;
		ICategory i_cat;
		JCategory j_cat;
};

TEST_F(InsCategoryTest, RInstructions) {
	std::vector<std::string> r_ins;
	r_ins.push_back("add");
	r_ins.push_back("sub");
	r_ins.push_back("div");
	r_ins.push_back("mul");

	
	for(int i = 0; i < r_cat.get_instructions().size(); i++) {
		EXPECT_EQ(r_ins[i], r_cat.get_instructions()[i]);
	}
}

TEST_F(InsCategoryTest, ICategory) {
	std::vector<std::string> i_ins;
	i_ins.push_back("load");
	i_ins.push_back("store");
	i_ins.push_back("addi");
	i_ins.push_back("subi");
	i_ins.push_back("bne");

	
	for(int i = 0; i < r_cat.get_instructions().size(); i++) {
		EXPECT_EQ(i_ins[i], i_cat.get_instructions()[i]);
	}
}

TEST_F(InsCategoryTest, JCategory) {
	std::vector<std::string> j_ins;
	j_ins.push_back("jmp");

	
	for(int i = 0; i < j_cat.get_instructions().size(); i++) {
		EXPECT_EQ(j_ins[i], j_cat.get_instructions()[i]);
	}
}

class PoperTableTest : public ::testing::Test {
	protected:
		PoperTable popert;
		RCategory r_cat;
		ICategory i_cat;
		JCategory j_cat;
	void SetUp() override {
		popert.add_category(std::unique_ptr<RCategory>(new RCategory()));
		popert.add_category(std::unique_ptr<ICategory>(new ICategory()));
		popert.add_category(std::unique_ptr<JCategory>(new JCategory()));
	}
};

TEST_F(PoperTableTest, CategoryInstructions) {
	InsCategory * r_cat = popert.get_category("add");
	InsCategory * i_cat = popert.get_category("addi");
	InsCategory * j_cat = popert.get_category("jmp");

	InsCategory * no_cat = popert.get_category("asd");
	EXPECT_TRUE(dynamic_cast<RCategory *>(r_cat) != nullptr);
	EXPECT_TRUE(dynamic_cast<ICategory *>(i_cat) != nullptr);
	EXPECT_TRUE(dynamic_cast<JCategory *>(j_cat) != nullptr);

	EXPECT_TRUE( no_cat == nullptr);
}

class ASMParserTest : public ::testing::Test {
	protected:
		ASMParser asm_parser;

};

TEST_F(ASMParserTest, BasicFunctions) {
	EXPECT_TRUE(asm_parser.valid_register("$zero"));
	EXPECT_TRUE(asm_parser.valid_register("$r0"));
}
