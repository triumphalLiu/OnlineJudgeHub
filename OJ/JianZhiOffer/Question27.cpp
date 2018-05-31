#include "global.h"

class Solution {
	/*Question 27 �ַ���������
	*��Ŀ����
	*	����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ,���ֵ����ӡ�����ַ������ַ����������С�
	*	���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	��������
	*	���ȴӺ���ǰ�ҵ�һ���Ⱥ�һ���ַ�С���ַ�x�����Ҳ���ʱ�˳��� ��acb��a  
	*	Ȼ��������ַ�x�����ҵ�һ�������������ұ������ַ�y����acb��b
	*	Ȼ�󽻻��ַ�x���ַ�y��λ�á� �������bca
	*	Ȼ���ַ�y��λ�ú�����ַ����������С� �������bac
	*/
public:
	vector<string> Permutation(string str) {
		vector<string> result;
		if (str.length() == 0) return result;
		sort(str.begin(), str.end());
		result.push_back(str);
		if (str.length() == 1) return result;
		while (1) {
			int charLess = str.length() - 1;
			while (!(str[charLess - 1] < str[charLess])) {
				charLess -= 1;
				if (charLess == 0)
					return result;
			}
			charLess -= 1;
			int charLarger = charLess + 1; 
			while (charLarger < str.length() && str[charLarger] > str[charLess]) 
				charLarger++;
			charLarger -= 1;
			char temp = str[charLess];
			str[charLess] = str[charLarger];
			str[charLarger] = temp;
			for (int i = charLess + 1; i < (str.length() + charLess + 1) / 2; ++i) {
				temp = str[i];
				str[i] = str[str.length() + (charLess + 1) - i - 1];
				str[str.length() + (charLess + 1) - i - 1] = temp;
			}
			result.push_back(str);
		}
		return result;
	}

	/*Use For Debug*/
	int Debug() {
		string str = "abc";
		vector<string> result = Permutation(str);
		for (int i = 0; i < result.size(); ++i)
			cout << result[i].c_str() << endl;
		return 0;
	}
};