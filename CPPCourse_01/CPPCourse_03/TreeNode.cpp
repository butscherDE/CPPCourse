#include "stdafx.h"
#include "TreeNode.h"
#include <memory>
#include <iostream>

TreeNode::TreeNode(TreeNode* parent, int key)
{
	m_parent = parent;
	m_key = key;
	addChild(-1);
	addChild(-1);
}


TreeNode::~TreeNode()
{
}

TreeNode* TreeNode::addChild(int key)
{
	m_children.push_back(std::make_unique<TreeNode>(this, key));
	return m_children.back().get();
}

TreeNode * TreeNode::addChild(int key, int pos)
{
	if (pos > 1) {
		std::cerr << "Tried to add to a out-of-bounds position at a binary tree" << std::endl;
	}
	//FIXME: Überschreiben gute Idee bezüglich memory management?
	m_children[pos] = std::make_unique<TreeNode>(this, key);
	return m_children.back().get();
}

std::vector<TreeNode*> TreeNode::getChildren()
{
	std::vector<TreeNode*> children;
	for (auto curr = m_children.begin(); curr != m_children.end(); curr++) {
		children.push_back(curr->get());
	}

	return children;
}

int TreeNode::getKey()
{
	return m_key;
}
