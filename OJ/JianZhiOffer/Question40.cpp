#include "global.h"

class Solution {
	/*Question 40 ������ֻ����һ�ε�����
	*��Ŀ����
	*	һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	������ͬ�����������Ľ��Ϊ0����ô��ȫ�����ֽ�����������õ��Ľ����������Ŀ�����ֵ��������
	*	�ҳ��������1����ͳ���λ��������������ͬ��λ��Ȼ��ԭ�����λΪ1����0���ֳ����飬
	*	�ֱ��ٴ���򣬾͵õ�������ֻ���ֹ�һ�ε����֡�
	*	Hint: ����2��n�η����������ƣ�ģ2������&1
	*/
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int allExOrResult = 0;
		for (int i = 0; i < data.size(); ++i)
			allExOrResult ^= data[i];
		int index = 1;
		while (!(allExOrResult & 1)) {
			++index;
			allExOrResult >>= 1;
		}
		vector<int> dataSet1, dataSet2;
		for (int i = 0; i < data.size(); ++i) {
			if ((data[i] >> (index - 1)) & 1)
				dataSet1.push_back(data[i]);
			else
				dataSet2.push_back(data[i]);
		}
		int number1 = 0, number2 = 0;
		for (int i = 0; i < dataSet1.size(); ++i)
			number1 ^= dataSet1[i];
		for (int i = 0; i < dataSet2.size(); ++i)
			number2 ^= dataSet2[i];
		num1[0] = number1;
		num2[0] = number2;
	}
};