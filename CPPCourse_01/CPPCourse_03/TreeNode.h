#pragma once

#include <memory>
#include <vector>

class TreeNode
{
public:
	TreeNode(TreeNode* parent, int key);
	~TreeNode();

	TreeNode* addChild(int key);
	TreeNode* addChild(int key, int pos);

	std::vector<TreeNode*> getChildren();

	int getKey();

private:
	TreeNode* m_parent;

	std::unique_ptr<std::vector<std::unique_ptr<TreeNode>>> m_children;

	int m_key;
};

