#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 1e3 + 10;
int a[maxn], b[maxn], m[maxn];
char m_str[maxn];

class Solution {
public:
	void swap(char &ch1, char &ch2)
	{
		char ch = ch1; ch1 = ch2; ch2 = ch;
		return;
	}

    string multiply(string num1, string num2) {
		if (num1=="" || num2=="") return "";
		int non_zero;
		for (non_zero = 0; non_zero<num1.length() && num1[non_zero]=='0'; ++non_zero) ;
		num1 = num1.substr(non_zero, num1.length());
		for (non_zero = 0; non_zero<num2.length() && num2[non_zero]=='0'; ++non_zero) ;
		num2 = num2.substr(non_zero, num2.length());
		if (num1=="" || num2=="") return "0";

		int len1 = num1.length(), len2 = num2.length();
		for (int i = 0; i < len1/2; ++i) swap(num1[i], num1[len1-1-i]);
		for (int i = 0; i < len2/2; ++i) swap(num2[i], num2[len2-1-i]);

		memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b)); memset(m, 0, sizeof(m));
		memset(m_str, 0, sizeof(m_str));
		for (int i = 0; i < len1; ++i) a[i] = num1[i]-'0';
		for (int i = 0; i < len2; ++i) b[i] = num2[i]-'0';
		for (int i = 0; i < len1; ++i) {
			for (int j = 0; j < len2; ++j) {
				m[i+j] += a[i]*b[j];
				m[i+j+1] += m[i+j]/10;
				m[i+j] %= 10;
			}
		}
		int len = len1+len2;
		while (!m[len-1]) --len;
		for (int i = 0; i < len; ++i) m_str[i] = m[i]+'0';
		m_str[len] = '\0';
		for (int i = 0; i < len/2; ++i) swap(m_str[i], m_str[len-1-i]);
		return m_str;
    }
};

int main()
{
	Solution sol;
	cout << sol.multiply("9", "9") << endl;
	return 0;
}