#include "global.h"

class Solution {
	/*Question 60 �Ѷ�������ӡ�ɶ���
	*��Ŀ����
	*	���ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	��α���������ǰ�ڵ㱣�������A�У�������һ��ʱ������ǰ����A��������B����յ�ǰ����A��
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