#include "global.h"

class Solution {
	/*Question 49 ���ַ���ת��������
	*��Ŀ����
	*	��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	���ַ�����ÿһλ���б����������������ţ����ж��Ƿ��ǵ�һλ���Ƿ��ǼӼ��ţ������ǺϷ���ֵ��
	*	��������֣���ô����������������һ�μ��㿪ʼǰ��10.
	*	��󽫷��ź�������˼��ɡ�
	*/
public:
	int StrToInt(string str) {
		if (str.length() == 0) return 0;
		int result = 0, sign = 1;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] >= '0' && str[i] <= '9') {
				result *= 10;
				result += (str[i] - '0');
			}
			else {
				if (i == 0 && str[i] == '-')
					sign = -1;
				else if (i == 0 && str[i] == '+')
					sign = 1;
				else return 0;
			}
		}
		return sign * result;
	}
};