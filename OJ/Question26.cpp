#include "global.h"

class Solution {
	/*Question 26 二叉搜索树与双向链表
	*题目描述
	*	输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
	*	要求不能创建任何新的结点，只能调整树中结点指针的指向。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	二叉搜索树的特点：左子树<根节点<右子树
	*	中序遍历并把结果保存到队列queue中，然后按顺序链接即可。
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