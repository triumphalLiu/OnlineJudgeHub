#include "global.h"

class Solution {
	/*Question 61 ���л�������
	*��Ŀ����
	*	��ʵ�������������ֱ��������л��ͷ����л�������
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	���л���ʹ�ò�α���(BFS)���л������սڵ㱣��Ϊ#����|������Ϊ���֡�
	*	�����л����ָ������л��Ĳ�֣����浽�ַ��������С�����ÿһ����Ϊ#���ַ���������һ���µĽڵ㲢�����ַ������ݸ�ֵ������������顣Ȼ���������λ�����ڵ㣩��ʼ������˳��������ӡ�
	*/
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
		}
	};
public:
	char* Serialize(TreeNode *root) {
		string str = "";
		queue<TreeNode *> treeQueue;
		treeQueue.push(root);
		while (treeQueue.empty() == false) {
			TreeNode *currRoot = treeQueue.front();
			treeQueue.pop();
			if (currRoot == NULL) {
				str += "#|";
			}
			else {
				str += to_string(currRoot->val);
				str += "|";
				treeQueue.push(currRoot->left);
				treeQueue.push(currRoot->right);
			}
		}
		char *result = new char[str.length() + 1];
		strcpy(result, str.c_str());
		return result;
	}

	TreeNode* Deserialize(char *str) {
		if (str == NULL || strcmp(str, "") == 0 || strcmp(str, "#|") == 0) return NULL;
		int depth = -1, base = 1;
		vector <string> strArray;
		vector <TreeNode *> nodeArray;
		string temp = "";
		for (int i = 0; i < (int)strlen(str); ++i) {
			if (str[i] == '|') {
				strArray.push_back(temp);
				temp = "";
			}
			else 
				temp += str[i];
		}
		for (int i = 0; i < (int)strArray.size(); ++i) {
			if (strcmp(strArray[i].c_str(), "#") == 0)
				nodeArray.push_back(NULL);
			else 
				nodeArray.push_back(new TreeNode(atoi(strArray[i].c_str())));
		}
		for (int i = 0, j = 1; i < (int)nodeArray.size(); ++i) {
			if (strcmp(strArray[i].c_str(), "#") == 0)
				continue;
			nodeArray[i]->left = nodeArray[j++];
			nodeArray[i]->right = nodeArray[j++];
		}
		return nodeArray[0];
	}

	/*Use For Debug*/
	int Debug() {
		char arr[20] = "1|2|#|3|43|#|#|#|#|";
		assert(strcmp(arr, Serialize(Deserialize(arr))) == 0);
		return 0;
	}
};