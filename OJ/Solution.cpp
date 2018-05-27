#include "global.h"

class Solution {
public:
	/*Question 1
	*��Ŀ����
	*	��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
	*   �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�����Ͻǿ�ʼ��飬���С��Ŀ�꣬�ͷ�����һ�У��������Ŀ�꣬�ͷ�����һ�У�Ȼ�����С��ľ�����б�����
	*/
	bool Find(int target, vector<vector<int> > array) {
		int col = array[0].size();
		for (int i = 0; i < array.size(); ++i) {
			for (int j = col - 1; j >= 0; --j) {
				if (array[i][j] == target)
					return true;
				else if (j == col - 1 && array[i][j] < target)
					break;
				else if (j == col - 1 && array[i][j] > target)
					j = (col -= 1);
			}
		}
		return false;
	}

	/*Question 2
	*��Ŀ����
	*	��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
	*	���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	ͳ�ƿո���������ٴӺ���ǰ�����滻��
	*/
	void replaceSpace(char *str, int length) {
		int spaceCount = 0;
		for (int i = 0; i < length; ++i)
			if (str[i] == ' ')
				spaceCount++;
		int newLen = spaceCount * 2 + length;
		str[newLen] = '\0';
		for (int i = length - 1; i >= 0; --i) {
			if (str[i] != ' ')
				str[i + spaceCount * 2] = str[i];
			else if (str[i] == ' ') {
				str[i + spaceCount * 2] = '0';
				str[i + spaceCount * 2 - 1] = '2';
				str[i + spaceCount * 2 - 2] = '%';
				spaceCount--;
			}
		}
	}

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

	/*Question 4
	*��Ŀ����
	*	����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
	*	���������ǰ���������������Ľ���ж������ظ������֡�
	*	��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
	*	struct TreeNode {
	*		int val;
	*		TreeNode *left;
	*		TreeNode *right;
	*		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	*	};
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�ݹ�˼�룬����ǰ������ĵ�һλȷ�����ڵ㣬�ٴ�����������ҵ������������ڸ��ڵ�֮ǰ�������������ڸ��ڵ�֮�������������
	*/
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0 || vin.size() == 0)
			return NULL;
		TreeNode *root = new TreeNode(pre[0]);
		cout << root->val << endl;
		for (int i = 0; i < vin.size(); ++i) {
			if (vin[i] == root->val) {
				vector<int> vinleft(vin.begin(), vin.begin() + i);
				vector<int> vinright(vin.begin() + i + 1, vin.end());
				vector<int> preleft(pre.begin() + 1, pre.begin() + i + 1);
				vector<int> preright(pre.begin() + i + 1, pre.end());
				root->left = reConstructBinaryTree(preleft, vinleft);
				root->right = reConstructBinaryTree(preright, vinright);
				return root;
			}
		}
		return NULL;
	}
};

int main() {
	Solution solution;
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> vin = { 4,7,2,1,5,3,8,6 };
	solution.reConstructBinaryTree(pre, vin);
	return 0;
}