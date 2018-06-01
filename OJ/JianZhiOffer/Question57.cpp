#include "global.h"

class Solution {
	/*Question 57 二叉树的下一个结点
	*题目描述
	*	给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	1、如果有右子树，那么结果就是 当前节点的右节点作为根的树 的直到左节点为空的节点。
	*	2、如果没有右子树，那么一直往上找，直到到树根或者当前节点的父节点的左节点等于当前节点。
	*/
	struct TreeLinkNode {
		int val;
		struct TreeLinkNode *left;
		struct TreeLinkNode *right;
		struct TreeLinkNode *next;
		TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
	};
public:
	TreeLinkNode * GetNext(TreeLinkNode* pNode)	{
		if (pNode == NULL) return NULL;
		else if (pNode->right != NULL) {
			TreeLinkNode *p = pNode->right;
			while (p->left != NULL) 
				p = p->left;
			return p;
		}
		else if (pNode->right == NULL) {
			TreeLinkNode *p = pNode;
			while (p->next != NULL) {
				if (p->next->left == p)
					return p->next;
				p = p->next;
			}
		}
		return NULL;
	}
};