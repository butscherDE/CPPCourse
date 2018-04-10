#pragma once

#include "TreeNode.h"
#include <memory>

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void printChildrens();
	void printChildrens(TreeNode * node, const int height);

	void addNode(int key);
	void addNode(TreeNode* node, int key);

private:
	std::unique_ptr<TreeNode> m_root;
};

