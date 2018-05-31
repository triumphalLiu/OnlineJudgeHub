#include "global.h"

class Solution {
	/*Question 55 �����л�����ڽ��
	*��Ŀ����
	*	һ�������а����������ҳ�������Ļ�����ڽ�㡣
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	����1��ʹ��map���ݽṹ������ÿ����ַ��һ������ָʾ�Ƿ��Ѿ����ʹ���bool����
	*	����2��Recommend������������ָ�룬һ��fast��һ��slow������л�����ôfastһ�����slow������
	*	Ȼ��fast��Ϊ��㣬��slow������ͬ���ٶ��ߣ���ô��������ǻ�����㡣����ѧ��ʽ���Ƶ���
	*/
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};
public:
	ListNode * EntryNodeOfLoop(ListNode* pHead) {
		ListNode *fast, *slow, *point;
		fast = slow = point = pHead;
		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				fast = pHead;
				while (fast != slow) {
					fast = fast->next;
					slow = slow->next;
				}
				return slow;
			}
		}
		return NULL;
	}

	ListNode * EntryNodeOfLoop_Way2(ListNode* pHead) {
		if (pHead == NULL) return NULL;
		map<ListNode *, bool> nodeMap;
		ListNode *p = pHead;
		while (true) {
			if (nodeMap[p] == true)
				return p;
			nodeMap[p] = true;
			p = p->next;
		}
	}
};