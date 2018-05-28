#include "global.h"

class Solution {
	/*Question 14 �����е�����k�����
	*��Ŀ����
	*	����һ����������������е�����k����㡣
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	˳�������˳�򱣴浽�����У���ȡ�����
	*	Note:array.size()��k����unsigned���ͣ����Ҫǿ��ת��Ϊint�ͣ�����k>array.size()��ʱ���Խ�硣
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