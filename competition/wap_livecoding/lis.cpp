#include <iostream>
#include <string>
using namespace std;

string longest_increasing_substring(const string &s) {
    if (s.length() < 2) return s;
    string str = s.substr(0, 1), max_str = str;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] > s[i-1]) str += s[i];
        else {
            if (str.length() > max_str.length()) max_str = str;
            str = s.substr(i, 1);
        }
    }
    return str.length()>max_str.length() ? str : max_str;
}

//int main() {
//    string s; cin >> s;
//    cout << longest_increasing_substring(s) << endl;
//    return 0;
//}
