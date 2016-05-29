#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (first_half.empty()) {
            first_half.push(num);
            return;
        }


        if (first_half.size() == second_half.size()) {
            if (num > second_half.top()) {
                first_half.push(second_half.top());
                second_half.pop();
                second_half.push(num);
            } else {
                first_half.push(num);
            }
            return;
        }

        if (num < first_half.top()) {
            second_half.push(first_half.top());
            first_half.pop();
            first_half.push(num);
        } else {
            second_half.push(num);
        }

        return;
    }

    // Returns the median of current data stream
    double findMedian() {
        if (first_half.size() == second_half.size()) {
            return (first_half.top()+second_half.top()) / 2.0;
        }
        return first_half.top();
    }

private:
    // max heap
    priority_queue<int, vector<int>, less<int> > first_half;

    // min heap
    priority_queue<int, vector<int>, greater<int> > second_half;
};

int main() {
    MedianFinder mf;
    mf.addNum(1); mf.addNum(2);
    cout << mf.findMedian() << endl;
    mf.addNum(3);
    cout << mf.findMedian() << endl;
    return 0;
}