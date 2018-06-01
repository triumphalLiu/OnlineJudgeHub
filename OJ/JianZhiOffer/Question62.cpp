#include "global.h"

class Solution {
	/*Question 62 二叉搜索树的第k个结点
	*题目描述
	*	给定一颗二叉搜索树，请找出其中的第k大的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	中序遍历的第K个结果即为所求。
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
	TreeNode * KthNode(TreeNode* pRoot, int k) {
		if (k == 0) return NULL;
		TreeNode *currNode = pRoot;
		int index = 0;
		stack<TreeNode *> treeStack;
		while (currNode != NULL || treeStack.empty() == false) {
			while (currNode != NULL) {
				treeStack.push(currNode);
				currNode = currNode->left;
			}
			currNode = treeStack.top();
			treeStack.pop();
			if (++index == k)
				break;
			currNode = currNode->right;
		}
		return currNode;
	}
};