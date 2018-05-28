#include "global.h"

class Solution {
	/*Question 15 反转链表
	*题目描述
	*	输入一个链表，反转链表后，输出链表的所有元素。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	顺序遍历链表，记录上一位置，当前位置和下一位置，并且修改当前节点的指向。
	*/
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};
public:
	ListNode * ReverseList(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode *pBefore = pHead;
		ListNode *pAfter = pHead->next;
		pBefore->next = NULL;
		while (pAfter != NULL) {
			ListNode *pTemp = pAfter->next;
			pAfter->next = pBefore;
			pBefore = pAfter;
			pAfter = pTemp;
		}
		return pBefore;
	}
};