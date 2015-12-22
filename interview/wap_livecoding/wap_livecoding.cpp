#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

bool has_nextpermutation(string &s)
{
    for (int i = s.length()-2; i >= 0; --i) {
        int ii = i+1;
        if (s[i] < s[ii]) {
            int j = s.length();
            while (s[i] >= s[--j]) ;
            swap(s[i], s[j]);
            for (int k = 0; k < (s.length()-ii)/2; ++k) {
                swap(s[ii+k], s[s.length()-1-k]);
            }
            return true;
        }
    }
    return false;
}

//int main()
//{
//    string s = "qwertyuiopasdfghjkl";
//    sort(s.begin(), s.end());
//    do {
//        // cout << s << endl;
//    } while (has_nextpermutation(s));
//    return 0;
//}
