#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    long long sum = 0LL;
    for (int i = 0; i < A.size(); ++i) {
        sum += A[i];
    }

    long long sum_lower = 0LL, sum_higher = sum;
    // enum p
    for (int p = 0; p < A.size(); ++p) {
        if (p > 0) {
            sum_lower += A[p-1];
        }
        sum_higher -= A[p];

        if (sum_lower == sum_higher) {
            return p;
        }
    }
    return -1;
}

int main() {
    int a[] = {-1, 3, -4, 5, 1, -6, 2, 1};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    cout << solution(v) << endl;
    return 0;
}