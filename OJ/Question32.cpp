#include "global.h"

class Solution {
	/*Question 32 �������ų���С����
	*��Ŀ����
	*	����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
	*	������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323����
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�����ڵ�������ƴ�Ӳ������ַ����Ĺ���Ƚϴ�С����С�ķ���ǰ�档���ͳһƴ�ӡ�
	*	Hint:��ʹ��stl����sort(a,b,function)����function����Ϊstatic��;
	*	Hint:to_string(...) ��ͷ�ļ�<sstream>��
	*/
public:
	string PrintMinNumber(vector<int> numbers) {
		for (int i = 0; i < numbers.size(); ++i) {
			for (int j = 1; j < numbers.size(); ++j) {
				int a = numbers[j - 1], b = numbers[j];
				string arrA = to_string(a);
				arrA += to_string(b);
				string arrB = to_string(b);
				arrB += to_string(a);
				if (arrA > arrB) {
					int temp = numbers[j - 1];
					numbers[j - 1] = numbers[j];
					numbers[j] = temp;
				}
			}
		}
		string result = "";
		for (int i = 0; i < numbers.size(); ++i)
			result += to_string(numbers[i]);
		return result;
	}
};