#include "global.h"

class Solution {
	/*Question 36 两个链表的第一个公共结点
	*题目描述
	*	输入两个链表，找出它们的第一个公共结点。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	思路1：
	*	分别遍历一遍链表1和链表2，把地址和访问次数记录，
	*	然后再遍历一遍链表1（因为map会排序，所以不能直接遍历map），如果次数等于2，则表示这是一个公共节点。
	*	时间复杂度：O(3n)
	*	思路2：
	*	让两个指针同时前进，若相等即为所求；若不相等且走到底，则指针指向另一条链表。
	*/
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};
public:
	ListNode * FindFirstCommonNode_Way1(ListNode* pHead1, ListNode* pHead2) {
		map<ListNode *, int> nodeMap;
		ListNode *pp1 = pHead1;
		while (pp1 != NULL) {
			if (nodeMap[pp1] == 1)
				break;
			nodeMap[pp1]++;
			pp1 = pp1->next;
		}
		ListNode *pp2 = pHead2;
		while (pp2 != NULL) {
			if (nodeMap[pp1] == 2)
				break;
			nodeMap[pp2]++;
			pp2 = pp2->next;
		}
		pp1 = pHead1;
		while (pp1 != NULL) {
			if (nodeMap[pp1] == 2)
				break;
			pp1 = pp1->next;
		}
		return pp1;
	}

	ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		ListNode *pp1 = pHead1, *pp2 = pHead2;
		while (pp1 != pp2) {
			if (pp1 != NULL) pp1 = pp1->next;
			if (pp2 != NULL) pp2 = pp2->next;
			if (pp1 == pp2)
				break;
			else if (pp1 == NULL)
				pp1 = pHead2;
			else if (pp2 == NULL)
				pp2 = pHead1;
		}
		return pp1;
	}
};