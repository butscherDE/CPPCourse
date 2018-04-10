// CPPCourse_03.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "TreeNode.h"
#include <memory>
#include <iostream>
#include "BinaryTree.h"

void printChildrens(TreeNode* node, const int height) {
	std::string indention;
	for (int i = 0; i < height - 1; i++) {
		std::cout << "    ";
	}
	if (height) {
		std::cout << "+---";
	}
	std::cout << node->getKey() << std::endl;

	for (TreeNode* c : node->getChildren()) {
		printChildrens(c, height + 1);
	}
}

int main()
{
	auto one = std::make_unique<TreeNode>(nullptr, 1);
	TreeNode* two = one->addChild(2);
	TreeNode* three = one->addChild(3);
	TreeNode* four = two->addChild(4);
	TreeNode* five = two->addChild(5);
	TreeNode* six = two->addChild(6);
	TreeNode* seven = three->addChild(7);
	TreeNode* eight = three->addChild(8);
	TreeNode* nine = five->addChild(9);
	TreeNode* ten = five->addChild(10);

	printChildrens(one.get(), 0);




	auto binaryTree = std::make_unique<BinaryTree>();
	binaryTree->addNode(10);
	binaryTree->addNode(15);
	binaryTree->addNode(5);
	binaryTree->addNode(1);
	binaryTree->addNode(6);
	binaryTree->addNode(7);

	binaryTree->printChildrens();


	std::cin.ignore();
	return 0;
}

