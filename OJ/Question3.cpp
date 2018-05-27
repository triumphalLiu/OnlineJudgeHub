#include "global.h"

class Solution {
	/*Question 3
	*��Ŀ����
	*	����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��
	*   struct ListNode {
	*         int val;
	*         struct ListNode *next;
	*         ListNode(int x) :
	*               val(x), next(NULL) {
	*         }
	*   };
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	ʹ��ջ�����ݽṹ����˳���������ѹջ��Ȼ��һ��һ����ջ����vector�С�
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