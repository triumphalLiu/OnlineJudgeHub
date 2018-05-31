#include "global.h"

class Solution {
	/*Question 54 �ַ����е�һ�����ظ����ַ�
	*��Ŀ����
	*	��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
	*	���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"�������ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	ʹ��һ����������¼�ַ����ֵ�˳����ʹ��һ����������¼���ִ˴��������ڹ�ϣ����Ϊchar�������256�У���˿���ֱ�Ӵ���һ����̬���飩
	*	Ȼ��ͨ���������У�ͨ��ƥ���ϣ���ֵ�ҵ�������һ�ε�ֵ���ɡ�
	*	���㷨���Ӷ�O(1)����Ϊ������ֻ��ѭ��256�Ρ�
	*/
private:
	unsigned int timesArray[256];
	queue<char> chArray;

public:
	//Insert one char from stringstream
	void Insert(char ch) {
		if (++timesArray[ch] == 1)
			chArray.push(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce() {
		while (timesArray[chArray.front()] != 1) {
			chArray.pop();
			if (chArray.empty())
				return '#';
		}
		return chArray.front();
	}

	Solution() {
		memset(timesArray, 0, sizeof(unsigned) * 256);
	}
};