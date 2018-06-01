#include "global.h"

class Solution {
	/*Question 60 把二叉树打印成多行
	*题目描述
	*	从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	层次遍历，将当前节点保存进数组A中，遍历完一行时，将当前数组A保存进结果B，清空当前数组A。
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		if (pRoot == NULL) return {};
		vector<vector<int> > result;
		vector<int> currRow;
		queue<TreeNode *> treeQueue;
		treeQueue.push(pRoot);
		int count = 0, offset = 1;
		while (treeQueue.empty() == false) {
			TreeNode *currRoot = treeQueue.front();
			treeQueue.pop();
			currRow.push_back(currRoot->val);
			if (currRoot->left != NULL)
				treeQueue.push(currRoot->left);
			if (currRoot->right != NULL)
				treeQueue.push(currRoot->right);
			if (++count == offset) {
				offset = treeQueue.size();
				count = 0;
				result.push_back(currRow);
				currRow = {};
			}
		}
		return result;
	}
};