#include "global.h"

class Solution {
	/*Question 17 �����ӽṹ
	*��Ŀ����
	*	�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	���ȣ�һ���κ�һ�����ǿյģ���ôֱ�ӷ���false
	*	��Σ��ж��������Ƿ��������(B��A����ȣ���ֻ��A�ٲ��ֽڵ�)��
	*	�����ж���2�Ƿ�����1���������ӽṹ�������Ƿ�����1���������ӽṹ��
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