#include "global.h"

class Solution {
	/*Question 16 �ϲ��������������
	*��Ŀ����
	*	���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�ȴ���һ������һ���ڵ��������Ϊ�˷�ֹ����һ��������Ϊ�յ��������
	*	Ȼ��˳�������������ȡ��С��ͷ�ڵ����������
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