#include <iostream>
#include <string>
using namespace std;

string longest_increase_substring(string &s)
{
    int index = 0, curlen = 1, maxlen = -1;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i]>s[i-1] && ++curlen>maxlen) {
            maxlen = curlen;
            index = i;
        } else curlen = 1;
    }
    if (maxlen == 0) return s.substr(0, 1);
    return s.substr(index-maxlen+1, maxlen);
}

//int main()
//{
//    string s; cin >> s;
//    cout << longest_increase_substring(s) << endl;
//    return 0;
//}
