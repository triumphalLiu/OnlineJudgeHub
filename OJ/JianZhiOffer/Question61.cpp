#include "global.h"

class Solution {
	/*Question 61 序列化二叉树
	*题目描述
	*	请实现两个函数，分别用来序列化和反序列化二叉树
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	序列化：使用层次遍历(BFS)序列化树，空节点保存为#，用|符号作为区分。
	*	反序列化：现根据序列化的拆分，保存到字符串数组中。对于每一个不为#的字符串，创建一个新的节点并根据字符串内容赋值，并保存进数组。然后从数组首位（根节点）开始根据其顺序进行连接。
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