#include "global.h"

class Solution {
	/*Question 22 �������´�ӡ������
	*��Ŀ����
	*	�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	���ö����Ƚ��ȳ������ԣ������ӽڵ㶼���浽���еĺ���
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