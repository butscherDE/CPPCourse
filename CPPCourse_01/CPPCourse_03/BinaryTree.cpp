#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree()
{
}


BinaryTree::~BinaryTree()
{
}

void BinaryTree::printChildrens() {
	printChildrens(m_root.get(), 0);
}

void BinaryTree::printChildrens(TreeNode* node, const int height) {
	TreeNode* c1 = node->getChildren()[0];
	if (c1 != nullptr) {
		printChildrens(c1, height + 1);
	}

	for (int i = 0; i < height - 1; i++) {
		std::cout << "    ";
	}
	if (height) {
		std::cout << "+---";
	}
	std::cout << node->getKey() << std::endl;


	TreeNode* c2 = node->getChildren()[1];
	if (c2 != nullptr) {
		printChildrens(c2, height + 1);
	}

	/*for (TreeNode* c : node->getChildren()) {
		if (c != nullptr) {
			printChildrens(c, height + 1);
		}
	}*/
}

void BinaryTree::addNode(int key)
{
	if (m_root == nullptr) {
		m_root = std::make_unique<TreeNode>(nullptr, key);
	}
	else {
		addNode(m_root.get(), key);
	}
}

void BinaryTree::addNode(TreeNode* node, int key) {
	bool right = key >= node->getKey();
	TreeNode* childNode = node->getChildren()[right];
	if (childNode == nullptr) {
		node->addChild(key, right);
	}
	else {
		addNode(childNode, key);
	}
}
