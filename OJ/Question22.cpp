#include "global.h"

class Solution {
	/*Question 22 从上往下打印二叉树
	*题目描述
	*	从上往下打印出二叉树的每个节点，同层节点从左至右打印。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	利用队列先进先出的属性，将孩子节点都保存到队列的后面
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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> result;
		if (root == NULL) return result;
		queue<TreeNode *> treeQueue;
		treeQueue.push(root);
		while (treeQueue.empty() == false) {
			TreeNode *currentNode = treeQueue.front();
			treeQueue.pop();
			result.push_back(currentNode->val);
			if (currentNode->left != NULL)
				treeQueue.push(currentNode->left);
			if (currentNode->right != NULL)
				treeQueue.push(currentNode->right);
		}
		return result;
	}
};