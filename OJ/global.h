#pragma once
#pragma warning (disable:4996)

#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};