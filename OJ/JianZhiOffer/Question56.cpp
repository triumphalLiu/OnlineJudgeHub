#include "global.h"

class Solution {
	/*Question 56 ɾ���������ظ��Ľ��
	*��Ŀ����
	*	��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�ȴ���һ���Զ����ͷ�ڵ㣬���Ӹýڵ��pHead��Ȼ������ڵ㣬������һ�ڵ��ֵ�������ȣ�ɾ���ظ��ڵ㣬����p��
	*	�������ȣ������־λΪ1���¸��ڵ����ظ��ڵ�Ŀ�ʼ�ڵ㣩��ôɾ���¸��ڵ㣬Ȼ�����һλlast��p��
	*	��󷵻��Զ����ͷ�ڵ����һ�ڵ㼴��,���Ӷ�O(n)��ֻ�����һ������
	*	Example��1 2 2 3 3 �� HEAD 1 2 2 3 3 �� HEAD 1 2 X 3 3 �� HEAD 1 X X 3 3 �� HEAD 1 X X 3 X �� HEAD 1 X X X X �� return HEAD->next;
	*	Note:���β�ڵ����ظ��ģ���ôѭ���˳���Ҫɾ��last->next��
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
		if (newHead->val == pHead->val) newHead->val -= 1; //��ֹ������ȫ��INT_MAX,����ֻҪ��pHead��ͬ�����ˡ�
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