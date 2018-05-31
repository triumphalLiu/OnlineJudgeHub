#include "global.h"

class Solution {
	/*Question 46 �����ǵ���Ϸ(ԲȦ�����ʣ�µ���)
	*��Ŀ����
	*	����,��С������Χ��һ����Ȧ��Ȼ��,�����ָ��һ����m,�ñ��Ϊ0��С���ѿ�ʼ������(ע��С���ѵı���Ǵ�0��n-1)
	*	ÿ�κ���m-1���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ�����������ѡ����,���Ҳ��ٻص�Ȧ��,
	*	Ȼ���������һ��С���ѿ�ʼ,����0...m-1����....������ȥ....ֱ��ʣ�����һ��С���ѣ����ʣ�µ�С������˭��?
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	��ʽһ������һ����������ģ���������̣�ѭ�����������ǵ�ǰ�ڵ����һ�ڵ㻹�ǵ�ǰ�ڵ㡣
	*	��ʽ����ͨ�����ƹ�ʽ�� f[1]=0; f[i]=(f[i-1]+m)%i; 
	*/
public:
	/*Solution 2 of 2 - Recommend*/
	int LastRemaining_Solution(int n, int m) {
		if (n <= 0 || m <= 0) return -1;
		int curr = 0;
		for (int i = 2; i <= n; ++i) {
			curr = (curr + m) % i;
		}
		return curr;
	}

	/*Solution 1 of 2*/
	struct childNode{
		int val;
		childNode *next;
		childNode(int n, childNode *nxt) :val(n), next(nxt) {}
	};

	void removeNoNNode(childNode *&pHead, int n) {
		childNode *pC = pHead;
		for (int i = 0; i < n-2; ++i)
			pC = pC->next;
		childNode *pRemove = pC->next;
		pC->next = pC->next->next;
		pHead = pC->next;
		delete pRemove;
	}

	int LastRemaining_Solution_Way2(int n, int m) {
		childNode *nextNode = NULL, *lastNode = NULL;
		for (int i = n - 1; i >= 0; --i) {
			nextNode = new childNode(i, nextNode);
			if (lastNode == NULL) lastNode = nextNode;
		}
		lastNode->next = nextNode;
		while (nextNode->next != nextNode)
			removeNoNNode(nextNode, m);
		return nextNode->val;
	}

	/*Use For Debug*/
	int Debug() {
		cout << LastRemaining_Solution(5, 3) << endl;
		return 0;
	}
};