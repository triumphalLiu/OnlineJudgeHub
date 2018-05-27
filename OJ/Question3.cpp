#include "global.h"

class Solution {
	/*Question 3
	*题目描述
	*	输入一个链表，从尾到头打印链表每个节点的值。
	*   struct ListNode {
	*         int val;
	*         struct ListNode *next;
	*         ListNode(int x) :
	*               val(x), next(NULL) {
	*         }
	*   };
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	使用栈的数据结构，按顺序遍历链表并压栈，然后一个一个出栈放入vector中。
	*/
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> result;
		stack<int> middle;
		ListNode *pt = head;
		while (pt != NULL) {
			middle.push(pt->val);
			pt = pt->next;
		}
		while (middle.empty() == false) {
			result.push_back(middle.top());
			middle.pop();
		}
		return result;
	}
};