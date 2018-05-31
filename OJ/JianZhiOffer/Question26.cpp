#include "global.h"

class Solution {
	/*Question 26 ������������˫������
	*��Ŀ����
	*	����һ�ö��������������ö���������ת����һ�������˫������
	*	Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�������������ص㣺������<���ڵ�<������
	*	����������ѽ�����浽����queue�У�Ȼ��˳�����Ӽ��ɡ�
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
	TreeNode * Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL) return NULL;
		queue<TreeNode *> treeQueue;
		stack<TreeNode *> treeStack;
		TreeNode *currentRoot = pRootOfTree;
		while (currentRoot != NULL || treeStack.empty() == false) {
			while (currentRoot != NULL) {
				treeStack.push(currentRoot);
				currentRoot = currentRoot->left;
			}
			currentRoot = treeStack.top();
			treeStack.pop();
			treeQueue.push(currentRoot);
			currentRoot = currentRoot->right;
		}
		TreeNode *pHead = NULL, *pBefore = NULL, *pCurr = NULL, *pNext = NULL;
		while (treeQueue.empty() == false) {
			pCurr = treeQueue.front();
			treeQueue.pop();
			pNext = treeQueue.empty() ? NULL : treeQueue.front();
			pCurr->left = pBefore;
			pCurr->right = pNext;
			if (pHead == NULL) pHead = pCurr;
			pBefore = pCurr;
		}
		return pHead;
	}

	/*Use For Debug*/
	void DisplayNode(TreeNode *p) {
		while (p != NULL) {
			cout << p->val << " ";
			p = p->right;
		}
		cout << endl;
	}

	int Debug() {
		TreeNode *fir = new TreeNode(1);
		TreeNode *sec = new TreeNode(2);
		TreeNode *thr = new TreeNode(3);
		TreeNode *fou = new TreeNode(4);
		TreeNode *fiv = new TreeNode(5);
		TreeNode *six = new TreeNode(6);
		sec->left = fir; sec->right = thr;
		fou->left = sec;
		fiv->left = fou; fiv->right = six;
		DisplayNode(Convert(fiv));
		return 0;
	}
};