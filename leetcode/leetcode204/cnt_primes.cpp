#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;

//class Solution {
//public:
//    bool is_prime(int n) {
//        if (n == 1) return false;
//        else if (n == 2) return true;
//        for (int i = 2; i <= sqrt(1.0*n); ++i) {
//            if (n%i == 0) return false;
//        }
//        return true;
//    }
//
//    int countPrimes(int n) {
//        int cnt = 0;
//        for (int i = 2; i < n; ++i) {
//            if (is_prime(i)) ++cnt;
//        }
//        return cnt;
//    }
//};

class Solution {
public:
    void get_primes(vector<int> &prime, int n) {
        vector<bool> visit(n, false);
        for (int i = 2; i < n; ++i) {
            if (!visit[i]) {
                prime.push_back(i);
                for (int j = i; j < n; j += i) visit[j] = true;
            }
        }
        return;
    }

    int b_search(const vector<int> &prime, int n) {
        int left = 0, right = prime.size()-1;
        while (left <= right) {
            int mid = (left+right) >> 1;
            if (n < prime[mid]) right = mid-1;
            else if (n > prime[mid]) left = mid+1;
            else return mid-1;
        }
        return right;
    }

    int countPrimes(int n) {
        vector<int> prime; get_primes(prime, n);
        return b_search(prime, n)+1;
    }
};

int main() {
    Solution sol;
    while (true) {
        int n; cin >> n;
        cout << sol.countPrimes(n) << endl;
    }
    return 0;
}
