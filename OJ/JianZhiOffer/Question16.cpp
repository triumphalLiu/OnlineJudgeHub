#include "global.h"

class Solution {
	/*Question 16 合并两个排序的链表
	*题目描述
	*	输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	先创建一个仅有一个节点的新链表（为了防止其中一个子链表为空的情况），
	*	然后顺序遍历两个链表，取最小的头节点插入新链表。
	*/
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};
public:
	ListNode * Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode *pHead = new ListNode(-0x42);
		ListNode *p = pHead;
		while (1) {
			if (pHead1 == NULL && pHead2 == NULL)
				break;
			else if (pHead1 == NULL) {
				p->next = pHead2;
				break;
			}
			else if (pHead2 == NULL) {
				p->next = pHead1;
				break;
			}
			else {
				if (pHead1->val <= pHead2->val) {
					p->next = pHead1;
					pHead1 = pHead1->next;
					p->next->next = NULL;
					p = p->next;
				}
				else {
					p->next = pHead2;
					pHead2 = pHead2->next;
					p->next->next = NULL;
					p = p->next;
				}

			}
		}
		return pHead->next;
	}
};