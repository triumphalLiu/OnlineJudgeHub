#include "global.h"

class Solution {
	/*Question 25 复杂链表的复制
	*题目描述
	*	输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
	*	（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	1、复制新节点，并放置在原节点之后。
	*	2、将原节点的random匹配到新节点的random
	*	3、分离链表
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