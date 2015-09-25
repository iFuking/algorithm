#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//class Solution {
//public:
//	void swap(char &a, char &b)
//	{
//		char tmp = a; a = b; b = tmp;
//		return;
//	}
//
//    string addBinary(string a, string b) {
//		int a_int = 0, a_len = a.length();
//		for (int i = a_len-1; i >= 0; --i) a_int += (a[i]-'0')*pow(2.0, a_len-1-i);
//		int b_int = 0, b_len = b.length();
//		for (int i = b_len-1; i >= 0; --i) b_int += (b[i]-'0')*pow(2.0, b_len-1-i);
//
//		if (a_int==0 && b_int==0) return "0";
//		int sum = a_int+b_int;
//		string sum_ab = "";
//		while (sum > 0) {
//			sum_ab += (__int64)sum%2+'0';
//			sum /= 2;
//		}
//		int len_sum = sum_ab.length();
//		for (int i = 0; i < len_sum/2; ++i) swap(sum_ab[i], sum_ab[len_sum-1-i]);
//		return sum_ab;
//    }
//};


class Solution {
public:
	void swap(char &a, char &b)
	{
		char tmp = a; a = b; b = tmp;
		return;
	}

    string addBinary(string a, string b) {
        string sum="", tmp;
		if (a.length() > b.length()) { tmp = a; a = b; b = tmp; }
		int lena = a.length(), lenb = b.length(), incr = 0;
		for (int i = 0; i < lena/2; ++i) swap(a[i], a[lena-1-i]);
		for (int i = 0; i < lenb/2; ++i) swap(b[i], b[lenb-1-i]);

		for (int i = 0; i < lenb; ++i) {
			if (i < lena) {
				sum += (a[i]-'0'+b[i]-'0'+incr)%2+'0';
				if (a[i]-'0'+b[i]-'0'+incr < 2) incr = 0;
				else incr = 1;
			} else {
				sum += (b[i]-'0'+incr)%2+'0';
				if (b[i]-'0'+incr < 2) incr = 0;
				else incr = 1;
			}
		}
		if (incr == 1) sum += '1';
		int len_sum = sum.length();
		for (int i = 0; i < len_sum/2; ++i) swap(sum[i], sum[len_sum-1-i]);
		return sum;
    }
};

int main()
{
	Solution sol;
	sol.addBinary("1111", "111");
	return 0;
}


/*
"10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101"
"110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011"
*/