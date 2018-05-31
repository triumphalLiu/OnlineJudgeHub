#include "global.h"

class Solution {
	/*Question 39 平衡二叉树
	*题目描述
	*	输入一棵二叉树，判断该二叉树是否是平衡二叉树。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	平衡二叉树的子树都是平衡二叉树，且两个子树的高度差绝对值小于1.
	*	采用递归方法，从最底层开始比较所有的子树高度,一旦有返回-1（不成立）的，那么整棵树都都不成立。
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
	int treeHeight(TreeNode *root) {
		if (root == NULL) return 0;
		int leftHeight = treeHeight(root->left);
		if (leftHeight == -1) return -1;
		int rightHeight = treeHeight(root->right);
		if (rightHeight == -1) return -1;
		if (abs(leftHeight - rightHeight) > 1) return -1;
		else return max(leftHeight, rightHeight) + 1;
	}

	bool IsBalanced_Solution(TreeNode* pRoot) {
		return treeHeight(pRoot) == -1 ? false : true;
	}
};