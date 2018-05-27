#pragma once
#pragma warning (disable:4996)

#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

/* Question3 */
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

/* Question4 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};