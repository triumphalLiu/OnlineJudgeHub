#include "global.h"

class Solution {
	/*Question 39 ƽ�������
	*��Ŀ����
	*	����һ�ö��������жϸö������Ƿ���ƽ���������
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	ƽ�����������������ƽ��������������������ĸ߶Ȳ����ֵС��1.
	*	���õݹ鷽��������ײ㿪ʼ�Ƚ����е������߶�,һ���з���-1�����������ģ���ô������������������
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