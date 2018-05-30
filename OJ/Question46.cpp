#include "global.h"

class Solution {
	/*Question 46 孩子们的游戏(圆圈中最后剩下的数)
	*题目描述
	*	首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。(注：小朋友的编号是从0到n-1)
	*	每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
	*	然后从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友，最后剩下的小朋友是谁呢?
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	方式一、创建一个环形链表模拟上述过程，循环结束条件是当前节点的下一节点还是当前节点。
	*	方式二、通过递推公式， f[1]=0; f[i]=(f[i-1]+m)%i; 
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