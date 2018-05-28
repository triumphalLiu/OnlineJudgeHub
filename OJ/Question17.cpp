#include "global.h"

class Solution {
	/*Question 17 树的子结构
	*题目描述
	*	输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	首先，一旦任何一颗树是空的，那么直接返回false
	*	其次，判断两棵树是否是相等树(B和A根相等，且只比A少部分节点)。
	*	否则，判断树2是否是树1左子树的子结构，或者是否是树1右子树的子结构。
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
	bool isAlmostSameTree(TreeNode* pRoot1, TreeNode *pRoot2)	{
		if (pRoot2 == NULL)
			return true;
		else if (pRoot1 == NULL)
			return false;
		else if (pRoot1->val == pRoot2->val)
			return isAlmostSameTree(pRoot1->left, pRoot2->left) && isAlmostSameTree(pRoot1->right, pRoot2->right);
		else
			return false;
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)	{
		if (pRoot2 == NULL || pRoot1 == NULL)
			return false;
		else if (isAlmostSameTree(pRoot1, pRoot2))
			return true;
		else 
			return HasSubtree(pRoot1->right, pRoot2) || HasSubtree(pRoot1->left, pRoot2);
	}
};