#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left_most = max(A, E), right_most = min(C, G);
        int bottom_most = max(B, F), top_most = min(D, H);

        int overlapped = 0;
        if (left_most<right_most && bottom_most<top_most) {
            overlapped = (right_most-left_most)*(top_most-bottom_most);
        }

        return (C-A)*(D-B)+(G-E)*(H-F)-overlapped;
    }
};

int main() {
    Solution sol;
    sol.computeArea(1, 2, 3, 4, 5, 6, 7, 8);
    return 0;
}
