#include "global.h"

class Solution {
	/*Question 25 ��������ĸ���
	*��Ŀ����
	*	����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
	*	��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	1�������½ڵ㣬��������ԭ�ڵ�֮��
	*	2����ԭ�ڵ��randomƥ�䵽�½ڵ��random
	*	3����������
	*/
	struct RandomListNode {
		int label;
		struct RandomListNode *next, *random;
		RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
		}
	};
public:
	RandomListNode * Clone(RandomListNode* pHead)
	{
		if (pHead == NULL) return NULL;
		RandomListNode *p = pHead;
		RandomListNode *newHead = NULL;
		while (p != NULL) {
			RandomListNode *newNode = new RandomListNode(p->label);
			if (newHead == NULL)
				newHead = newNode;
			RandomListNode *pTemp = p->next;
			p->next = newNode;
			newNode->next = pTemp;
			p = pTemp;
		}
		p = pHead;
		while (p != NULL) {
			if (p->random != NULL)
				p->next->random = p->random->next;
			else
				p->next->random = NULL;
			p = p->next->next;
		}
		RandomListNode *pn = newHead;
		p = pHead;
		while (p != NULL && pn != NULL) {
			p->next = p->next->next;
			p = p->next;
			if (p == NULL)
				pn->next = NULL;
			else
				pn->next = p->next;
			pn = pn->next;
		}
		return newHead;
	}

	/*Use For Debug*/
	void Display(RandomListNode *p) {
		while (p != NULL) {
			cout << p->label << " ";
			p = p->next;
		}
		cout << endl;
	}

	int Debug() {
		RandomListNode *head = new RandomListNode(1);
		RandomListNode *sec = new RandomListNode(2);
		RandomListNode *thr = new RandomListNode(3);
		RandomListNode *fou = new RandomListNode(4);
		RandomListNode *fiv = new RandomListNode(5);
		head->next = sec;
		sec->next = thr;
		thr->next = fou;
		fou->next = fiv;
		fiv->next = NULL;
		head->random = thr;
		thr->random = fiv;
		sec->random = NULL;
		fou->random = sec;
		fiv->random = NULL;
		RandomListNode *p = this->Clone(head);
		Display(p);
		return 0;
	}
};