#include "global.h"

class Solution {
	/*Question 56 删除链表中重复的结点
	*题目描述
	*	在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	先创建一个自定义的头节点，连接该节点和pHead，然后遍历节点，保存上一节点的值，如果相等，删除重复节点，后移p；
	*	如果不相等，如果标志位为1（下个节点是重复节点的开始节点）那么删除下个节点，然后后移一位last和p，
	*	最后返回自定义的头节点的下一节点即可,复杂度O(n)，只需遍历一次链表。
	*	Example：1 2 2 3 3 → HEAD 1 2 2 3 3 → HEAD 1 2 X 3 3 → HEAD 1 X X 3 3 → HEAD 1 X X 3 X → HEAD 1 X X X X → return HEAD->next;
	*	Note:如果尾节点是重复的，那么循环退出后要删除last->next。
	*/
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};
public:
	ListNode * deleteDuplication(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL) return pHead;
		ListNode *newHead = new ListNode(INT_MAX);
		if (newHead->val == pHead->val) newHead->val -= 1; //防止链表中全是INT_MAX,反正只要和pHead不同就行了。
		newHead->next = pHead;
		ListNode *p = newHead->next;
		ListNode *lastP = newHead;
		int currValue = newHead->val;
		bool numberRepeat = false;
		while (p != NULL) {
			if (p->val == currValue) {
				numberRepeat = true;
				ListNode *temp = p->next;
				delete p;
				p = temp;
				lastP->next->next = temp;
			}
			else {
				if (numberRepeat) {
					if (lastP->next != NULL)
						delete lastP->next;
					lastP->next = p;
					numberRepeat = false;
				}
				if (lastP->next->next == p)
					lastP = lastP->next;
				currValue = p->val;
				p = p->next;
			}
		}
		if (numberRepeat) {
			if(lastP->next != NULL)
				delete lastP->next;
			lastP->next = NULL;
		}
		ListNode *result = newHead->next;
		delete newHead;
		return result;
	}

	/*Use For Debug*/
	int Debug() {
		ListNode *one = new ListNode(2);
		ListNode *two = new ListNode(2);
		ListNode *thr = new ListNode(3);
		ListNode *fou = new ListNode(3);
		ListNode *fiv = new ListNode(4);
		one->next = two; two->next = thr; thr->next = fou; fou->next = fiv; fiv->next = NULL;
		ListNode *p = this->deleteDuplication(one);
		while (p != NULL) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
		return 0;
	}
};