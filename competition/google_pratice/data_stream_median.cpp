#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void data_stream_median() {
    priority_queue<int, vector<int>, less<int> > first_half;
    priority_queue<int, vector<int>, greater<int> > second_half;

    vector<int> stream_median;

    while (true) {
        int n; cin >> n;
        
        if (first_half.size() == second_half.size()) {
            if (first_half.size() == 0) {
                first_half.push(n);
                stream_median.push_back(first_half.top());
                cout << first_half.top() << endl;
                continue;
            }

            if (second_half.top() < n) {
                first_half.push(second_half.top());
                second_half.pop();
                second_half.push(n);
            } else {
                first_half.push(n);
            }
        } else {
            if (second_half.size() == 0) {
                second_half.push(n);
                stream_median.push_back(first_half.top());
                cout << first_half.top() << endl;
                continue;
            }

            if (n < first_half.top()) {
                second_half.push(first_half.top());
                first_half.pop();
                first_half.push(n);
            } else {
                second_half.push(n);
            }
        }

        stream_median.push_back(first_half.top());
        cout << first_half.top() << endl;
    }
    return;
}

void solve() {
    data_stream_median();
    return;
}

int main() {
    solve();
    return 0;
}