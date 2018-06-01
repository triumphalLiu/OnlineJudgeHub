#include "global.h"

class Solution {
	/*Question 62 �����������ĵ�k�����
	*��Ŀ����
	*	����һ�Ŷ��������������ҳ����еĵ�k��Ľ�㡣���磬 5 / \ 3 7 /\ /\ 2 4 6 8 �У��������ֵ��С˳�����������ֵΪ4��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	��������ĵ�K�������Ϊ����
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