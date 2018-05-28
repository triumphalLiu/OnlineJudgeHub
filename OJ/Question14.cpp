#include "global.h"

class Solution {
	/*Question 14 链表中倒数第k个结点
	*题目描述
	*	输入一个链表，输出该链表中倒数第k个结点。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	顺序遍历并顺序保存到数组中，再取结果。
	*	Note:array.size()和k都是unsigned类型，相减要强制转化为int型，否则当k>array.size()的时候会越界。
	*/
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};
public:
	ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
		vector<ListNode *> array;
		ListNode *p = pListHead;
		while (p != NULL) {
			array.push_back(p);
			p = p->next;
		}
		if (array.empty() || (int)array.size() - (int)k < 0)
			return NULL;
		else
			return array[(int)array.size() - (int)k];
	}
};