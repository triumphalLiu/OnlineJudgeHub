#include "global.h"

class Solution {
	/*Question 36 ��������ĵ�һ���������
	*��Ŀ����
	*	�������������ҳ����ǵĵ�һ��������㡣
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	˼·1��
	*	�ֱ����һ������1������2���ѵ�ַ�ͷ��ʴ�����¼��
	*	Ȼ���ٱ���һ������1����Ϊmap���������Բ���ֱ�ӱ���map���������������2�����ʾ����һ�������ڵ㡣
	*	ʱ�临�Ӷȣ�O(3n)
	*	˼·2��
	*	������ָ��ͬʱǰ��������ȼ�Ϊ��������������ߵ��ף���ָ��ָ����һ������
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