#include "global.h"

class Solution {
	/*Question 18 �������ľ���
	*��Ŀ����
	*	���������Ķ�����������任ΪԴ�������ľ���
	*	�������ľ����壺
	*	Դ������ 
    *	    8
    *	   /  \
    *	  6   10
    *	 / \  / \
    *	5  7 9 11
    *	���������
    *	    8
    *	   /  \
    *	  10   6
    *	 / \  / \
    *	11 9 7  5
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�����ࣺ�ݹ�������ǿսڵ㡣
	*	��ʡջ�ռ䣺ʹ��stack���ݽṹ����ȳ������ԣ���ÿ���㵱����ǰ�����ĸ��ڵ���д���
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