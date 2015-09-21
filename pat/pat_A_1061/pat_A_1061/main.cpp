#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string week[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int to_hour(char ch)
{
	if (isdigit(ch)) return ch-'0';
	return ch-'A'+10;
}

void solve()
{
	string str1, str2, str3, str4;
	cin >> str1 >> str2 >> str3 >> str4;
	char ch1, ch2; int index;
	for (int i = 0; i<str1.length() && str2.length(); ++i) {
		if (str1[i]>='A' && str1[i]<='G' && str1[i]==str2[i]) { ch1 = str1[index=i]; break; } 
	}
	for (int i = index+1; i<str1.length() && i<str2.length(); ++i) {
		if (str1[i]==str2[i] && ((str1[i]>='0'&&str1[i]<='9') || (str1[i]>='A'&&str1[i]<='N'))) { ch2 = str1[i]; break; }
	}

	int minute;
	for (int i = 0; i<str3.length() && i<str4.length(); ++i) {
		if (str3[i] == str4[i] && isalpha(str3[i])) { minute = i; break; }
	}

	printf("%s %02d:%02d\n", week[ch1-'A'].c_str(), to_hour(ch2), minute);
	return;
}

int main()
{
	solve();
	return 0;
}