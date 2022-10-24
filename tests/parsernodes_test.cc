#include <gtest/gtest.h>

#include "Parser/parsernode.hpp"
#include "emu_utils.hpp"


TEST(NodeTest, RNodeCode) {
	uint16_t add_ins = create_r_ins(4, 0,0,1);
	uint16_t sub_ins = create_r_ins(5, 0,1,2);
	uint16_t mul_ins = create_r_ins(6, 1,1,2);
	uint16_t div_ins = create_r_ins(7, 2,1,1);

	RNode add_node;
	RNode sub_node;
	RNode mul_node;
	RNode div_node;

	add_node.set_node_type("add");
	add_node.src_one.reg = 0;
	add_node.src_two.reg = 0;
	add_node.dst.reg = 1;

	sub_node.set_node_type("sub");
	sub_node.src_one.reg = 0;
	sub_node.src_two.reg = 1;
	sub_node.dst.reg = 2;

	mul_node.set_node_type("mul");
	mul_node.src_one.reg = 1;
	mul_node.src_two.reg = 1;
	mul_node.dst.reg = 2;

	div_node.set_node_type("div");
	div_node.src_one.reg = 2;
	div_node.src_two.reg = 1;
	div_node.dst.reg = 1;

	EXPECT_EQ(add_ins, add_node.encoding(4));
	EXPECT_EQ(sub_ins, sub_node.encoding(5));
	EXPECT_EQ(mul_ins, mul_node.encoding(6));
	EXPECT_EQ(div_ins, div_node.encoding(7));
}

TEST(NodeTest, ICode) {
	uint16_t load_ins = create_i_ins(8, 0, 1,5);
	uint16_t store_ins = create_i_ins(9, 0, 1,5);
	uint16_t addi_ins = create_i_ins(10, 0, 1,4);
	uint16_t subi_ins = create_i_ins(11, 2, 3,8);

	INode load_node;
	INode store_node;
	INode addi_node;
	INode subi_node;

	load_node.set_node_type("load");
	load_node.reg_one.reg = 0;
	load_node.reg_two.reg = 1;
	load_node.constant.constant = 5;

	store_node.set_node_type("store");
	store_node.reg_one.reg = 0;
	store_node.reg_two.reg = 1;
	store_node.constant.constant = 5;

	addi_node.set_node_type("addi");
	addi_node.reg_one.reg = 0;
	addi_node.reg_two.reg = 1;
	addi_node.constant.constant = 4;

	subi_node.set_node_type("subi");
	subi_node.reg_one.reg = 2;
	subi_node.reg_two.reg = 3;
	subi_node.constant.constant = 8;

	EXPECT_EQ(load_ins, load_node.encoding(8));
	EXPECT_EQ(store_ins, store_node.encoding(9));
	EXPECT_EQ(addi_ins, addi_node.encoding(10));
	EXPECT_EQ(subi_ins, subi_node.encoding(11));
}
