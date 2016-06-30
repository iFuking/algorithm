#include <iostream>
using namespace std;

// This is a pure Math problem. We need the knowledge of number theory to 
// cover the proof and solution. No idea why microsoft uses this problem in 
// real interview.

// The basic idea is to use the property of Bézout's identity and check if 
// z is a multiple of GCD(x, y)

// Quote from wiki:

// Bézout's identity (also called Bézout's lemma) is a theorem in the 
// elementary theory of numbers:
// let a and b be nonzero integers and let d be their greatest common divisor. 
// Then there exist integers x and y such that ax+by=d
// In addition, the greatest common divisor d is the smallest positive integer 
// that can be written as ax + by
// every integer of the form ax + by is a multiple of the greatest common 
// divisor d.
// If a or b is negative this means we are emptying a jug of x or y gallons 
// respectively.

// Similarly if a or b is positive this means we are filling a jug of x or y 
// gallons respectively.

// x = 4, y = 6, z = 8.

// GCD(4, 6) = 2

// 8 is multiple of 2

// so this input is valid and we have:

// -1 * 4 + 6 * 2 = 8

// In this case, there is a solution obtained by filling the 6 gallon jug 
// twice and emptying the 4 gallon jug once. (Solution. Fill the 6 gallon 
// jug and empty 4 gallons to the 4 gallon jug. Empty the 4 gallon jug. 
// Now empty the remaining two gallons from the 6 gallon jug to the 4 gallon 
// jug. Next refill the 6 gallon jug. This gives 8 gallons in the end)



class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }

    bool canMeasureWater(int x, int y, int z) {
        if (z < 0) return false;
        if (z == 0) return true;
        if (x <= 0) return y==z;
        if (y <= 0) return x==z;
        if (x+y < z) return false;
        return z%gcd(x, y) == 0;
    }
};

int main() {
    Solution sol;
    while (true) {
        int x, y, z; cin >> x >> y >> z;
        cout << sol.canMeasureWater(x, y, z) << endl;
    }
    return 0;
}