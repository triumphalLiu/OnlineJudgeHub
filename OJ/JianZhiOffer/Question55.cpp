#include "global.h"

class Solution {
	/*Question 55 链表中环的入口结点
	*题目描述
	*	一个链表中包含环，请找出该链表的环的入口结点。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	方法1、使用map数据结构，保存每个地址和一个用于指示是否已经访问过的bool变量
	*	方法2（Recommend）、设置两个指针，一个fast，一个slow，如果有环，那么fast一定会和slow相遇。
	*	然后将fast置为起点，和slow按照相同的速度走，那么相遇点就是环的起点。（数学公式可推导）
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