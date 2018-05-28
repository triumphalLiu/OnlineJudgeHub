#include "global.h"

class Solution {
	/*Question 15 ��ת����
	*��Ŀ����
	*	����һ��������ת�����������������Ԫ�ء�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	˳�����������¼��һλ�ã���ǰλ�ú���һλ�ã������޸ĵ�ǰ�ڵ��ָ��
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