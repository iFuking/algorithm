class Solution {
public:
    bool isPerfectSquare(int num) {
    	double esp = 1e-8;
        double left = 0, right = num;
        while (fabs(left-right) > esp) {
        	double mid = left+(right-left)/2;
        	if (mid*mid-num < 0) left = mid;
        	else right = mid;
        }
        int left_int = left+0.5;
        // printf("%.9f\n", fabs(left-left_int));
        return fabs(left-left_int)<esp;
    }
};