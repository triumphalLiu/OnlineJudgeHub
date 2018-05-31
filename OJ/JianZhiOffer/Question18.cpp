#include "global.h"

class Solution {
	/*Question 18 二叉树的镜像
	*题目描述
	*	操作给定的二叉树，将其变换为源二叉树的镜像。
	*	二叉树的镜像定义：
	*	源二叉树 
    *	    8
    *	   /  \
    *	  6   10
    *	 / \  / \
    *	5  7 9 11
    *	镜像二叉树
    *	    8
    *	   /  \
    *	  10   6
    *	 / \  / \
    *	11 9 7  5
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	代码简洁：递归操作各非空节点。
	*	节省栈空间：使用stack数据结构后进先出的特性，把每个点当作当前子树的根节点进行处理。
	*/
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
		}
	};
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL) return;
		TreeNode *pTemp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = pTemp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}

	void Mirror_By_Stack(TreeNode *pRoot) {
		if (pRoot == NULL) return;
		stack<TreeNode *> treeStack;
		treeStack.push(pRoot);
		while (treeStack.empty() == false) {
			TreeNode *currentRoot = treeStack.top();
			treeStack.pop();
			TreeNode *pTemp = currentRoot->left;
			currentRoot->left = currentRoot->right;
			currentRoot->right = pTemp;
			if (currentRoot->left != NULL)
				treeStack.push(currentRoot->left);
			if (currentRoot->right != NULL)
				treeStack.push(currentRoot->right);
		}
	}
};