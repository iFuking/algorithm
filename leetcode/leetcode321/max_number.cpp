#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> merge_two_vec(vector<int>& nums1, vector<int>& nums2) {
		vector<int> v;
		int i = 0, j = 0;
		while (i<nums1.size() && j<nums2.size()) {
			if (nums1[i] < nums2[j]) {
				v.push_back(nums2[j]);
				++j;
			} else if (nums1[i] > nums2[j]) {
				v.push_back(nums1[i]);
				++i;
			} else {
				int i0 = i, j0 = j;
				while (i0<nums1.size() && j0<nums2.size() && nums1[i0]==nums2[j0]) {
					++i0; ++j0;
				}

				if (i0 == nums1.size()) {
					v.push_back(nums2[j]);
					++j;
				} else if (j0 == nums2.size()) {
					v.push_back(nums1[i]);
					++i;
				} else {
					if (nums1[i0] < nums2[j0]) {
						v.push_back(nums2[j]);
						++j;
					} else {
						v.push_back(nums1[i]);
						++i;
					}
				}
			}
		}
		
		if (i == nums1.size()) {
			for ( ; j < nums2.size(); ++j) {
				v.push_back(nums2[j]);
			}
		}
		if (j == nums2.size()) {
			for ( ; i < nums1.size(); ++i) {
				v.push_back(nums1[i]);
			}
		}

		// for (int i = 0; i < v.size(); ++i) {
		// 	printf("%d ", v[i]);
		// }
		// printf("\n");

		return v;
	}

	vector<vector<int> > gen_nums_len(vector<int>& nums) {
		vector<vector<int> > nums_len;
		nums_len.push_back(nums);

		// enum each len, decrease one each iteration
        for (int len = nums.size()-1; len >= 0; --len) {
        	bool is_find = false;
        	vector<int>::iterator iter = nums.begin();
        	for (int i = 1; i < nums.size(); ++i) {
        		if (nums[i-1] < nums[i]) {
        			iter = nums.erase(iter);
        			nums_len.push_back(nums);

        			is_find = true;
        			break;
        		}
        		++iter;
        	}
        	if (!is_find) {
        		nums.pop_back();
        		nums_len.push_back(nums);
        	}
        }
        reverse(nums_len.begin(), nums_len.end());

        // for (int i = 0; i < nums_len.size(); ++i) {
        // 	for (int j = 0; j < nums_len[i].size(); ++j) {
        // 		printf("%d ", nums_len[i][j]);
        // 	}
        // 	printf("\n");
        // }

        return nums_len;
	}

	vector<int> vec_cmp(vector<int> &v1, vector<int> &v2) {
		if (v1.size() == 0) return v2;
		if (v2.size() == 0) return v1;

		for (int i = 0; i < v1.size(); ++i) {
			if (v1[i] > v2[i]) return v1;
			else if (v1[i] < v2[i]) return v2;
		}
		return v2;
	}

	vector<int> divide_conquer(int left, int right, vector<vector<int> > &results) {
		if (left == right) return results[left];

		int mid = (left+right) >> 1;
		vector<int> v1 = divide_conquer(left, mid, results);
		vector<int> v2 = divide_conquer(mid+1, right, results);
		return vec_cmp(v1, v2);
	}

	vector<int> find_result(vector<vector<int> > &results) {
		vector<int> v = results[0];
		for (int i = 1; i < results.size(); ++i) {
			v = vec_cmp(v, results[i]);
		}
		return v;
		// return divide_conquer(0, results.size()-1, results);
	}

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<vector<int> > nums1_len = gen_nums_len(nums1);
        vector<vector<int> > nums2_len = gen_nums_len(nums2);

        vector<vector<int> > results;
        for (int i = 0; i <= k; ++i) {
        	if (i<nums1_len.size() && k-i<nums2_len.size()) {
        		// printf("%d %d\n", i, k-i);
        		results.push_back(merge_two_vec(nums1_len[i], nums2_len[k-i]));
        	}
        }

        // for (int i = 0; i < results.size(); ++i) {
        // 	for (int j = 0; j < results[i].size(); ++j) {
        // 		printf("%d ", results[i][j]);
        // 	}
        // 	printf("\n");
        // }


        return find_result(results);
    }
};

/*
[2,1,2,1,2,2,1,2,2,1,1,2,1,0,2,0,1,0,1,1,2,0,0,2,2,2,2,1,1,1,2,1,2,0,2,0,1,1,0,1,0,2,0,1,0,2,0,1,1,0,0,2,0,1,1,2,0,2,2,1,2,1,2,1,0,1,2,0,2,1,2,2,2,0,1,1,0,2,0,1,1,0,0,0,2,1,1,1,0,1,1,0,1,2,1,2,0,0,0,2,1,2,2,1,1,0,1,1,0,0,1,0,0,0,2,1,1,0,2,0,2,2,0,2,0,0,2,0,1,2,1,1,1,2,1,0,1,1,0,2,1,2,2,1,0,1,1,1,2,0,2,2,2,0,2,1,1,2,1,1,2,0,2,1,0,2,0,0,2,2,2,0,2,1,2,2,1,2,1,2,2,2,1,1,2,0,2,0,0,2,2,2,0,2,2,1,0,0,2,2,2,1,1,0,2,1,0,1,2,1,1,2,2,1,1,0,2,1,2,2,1,2,1,0,0,0,0,1,1,0,2,2,2,2,2,2,2,2,1,1,0,2,1,0,0,0,0,2,1,1]
[1,1,0,2,0,1,1,1,0,2,2,2,1,1,0,1,2,1,2,1,0,1,2,2,2,2,1,1,0,2,0,1,0,0,1,1,0,1,2,1,2,1,2,0,1,1,1,1,2,0,1,1,1,0,0,1,0,1,2,1,1,0,2,2,1,2,0,2,0,1,1,2,0,1,1,2,2,1,0,1,2,2,0,1,1,2,2,0,2,2,0,2,1,0,0,2,1,0,0,2,1,2,1,2,0,2,0,1,1,2,1,1,1,2,0,2,2,0,2,2,0,2,1,2,1,2,0,2,0,0,1,2,2,2,2,1,2,2,0,1,0,0,2,2,2,2,0,1,0,2,1,2,2,2,1,1,1,1,2,0,0,1,0,0,2,2,1,0,0,1,1,0,0,1,1,0,2,2,2,2,2,1,0,2,2,0,0,1,0,0,1,1,1,2,2,0,0,2,0,0,0,1,2,0,2,0,1,2,0,1,2,0,1,1,0,0,1,2,1,0,2,1,0,1,2,0,1,1,2,1,0,2,1,2,1,1,0,2,2,1,0,2,1,1,1,0,0,0,1,0]
500
*/

int main() {
    Solution sol;
    int a[] = {2,1,2,1,2,2,1,2,2,1,1,2,1,0,2,0,1,0,1,1,2,0,0,2,2,2,2,1,1,1,2,1,2,0,2,0,1,1,0,1,0,2,0,1,0,2,0,1,1,0,0,2,0,1,1,2,0,2,2,1,2,1,2,1,0,1,2,0,2,1,2,2,2,0,1,1,0,2,0,1,1,0,0,0,2,1,1,1,0,1,1,0,1,2,1,2,0,0,0,2,1,2,2,1,1,0,1,1,0,0,1,0,0,0,2,1,1,0,2,0,2,2,0,2,0,0,2,0,1,2,1,1,1,2,1,0,1,1,0,2,1,2,2,1,0,1,1,1,2,0,2,2,2,0,2,1,1,2,1,1,2,0,2,1,0,2,0,0,2,2,2,0,2,1,2,2,1,2,1,2,2,2,1,1,2,0,2,0,0,2,2,2,0,2,2,1,0,0,2,2,2,1,1,0,2,1,0,1,2,1,1,2,2,1,1,0,2,1,2,2,1,2,1,0,0,0,0,1,1,0,2,2,2,2,2,2,2,2,1,1,0,2,1,0,0,0,0,2,1,1};
    int b[] = {1,1,0,2,0,1,1,1,0,2,2,2,1,1,0,1,2,1,2,1,0,1,2,2,2,2,1,1,0,2,0,1,0,0,1,1,0,1,2,1,2,1,2,0,1,1,1,1,2,0,1,1,1,0,0,1,0,1,2,1,1,0,2,2,1,2,0,2,0,1,1,2,0,1,1,2,2,1,0,1,2,2,0,1,1,2,2,0,2,2,0,2,1,0,0,2,1,0,0,2,1,2,1,2,0,2,0,1,1,2,1,1,1,2,0,2,2,0,2,2,0,2,1,2,1,2,0,2,0,0,1,2,2,2,2,1,2,2,0,1,0,0,2,2,2,2,0,1,0,2,1,2,2,2,1,1,1,1,2,0,0,1,0,0,2,2,1,0,0,1,1,0,0,1,1,0,2,2,2,2,2,1,0,2,2,0,0,1,0,0,1,1,1,2,2,0,0,2,0,0,0,1,2,0,2,0,1,2,0,1,2,0,1,1,0,0,1,2,1,0,2,1,0,1,2,0,1,1,2,1,0,2,1,2,1,1,0,2,2,1,0,2,1,1,1,0,0,0,1,0};
    // int a[] = {1, 0, 2, 1, 0, 0, 0, 1};
    // int b[] = {1, 0, 2, 0, 1};

    vector<int> v1(a, a+sizeof(a)/sizeof(a[0]));
    printf("%d\n", (int)v1.size());
    vector<int> v2(b, b+sizeof(b)/sizeof(b[0]));
    printf("%d\n", (int)v2.size());

    for (int i = 0; i < v1.size(); ++i) {
    	printf("%d ", v1[i]);
    }
    printf("\n\n");

    for (int i = 0; i < v2.size(); ++i) {
    	printf("%d ", v2[i]);
    }
    printf("\n\n");

    vector<int> v = sol.merge_two_vec(v1, v2);
    // vector<int> v = sol.maxNumber(v1, v2, 500);
    for (int i = 0; i < v.size(); ++i) {
    	printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}