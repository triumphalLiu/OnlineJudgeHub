#include "global.h"

class Solution {
	/*Question 57 ����������һ�����
	*��Ŀ����
	*	����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	1�����������������ô������� ��ǰ�ڵ���ҽڵ���Ϊ������ ��ֱ����ڵ�Ϊ�յĽڵ㡣
	*	2�����û������������ôһֱ�����ң�ֱ�����������ߵ�ǰ�ڵ�ĸ��ڵ����ڵ���ڵ�ǰ�ڵ㡣
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