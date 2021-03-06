/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

/*
 * Binary search
*/

#include <algorithm>
#include "helper.h"

class Solution {
public:
    int findMin(vector<int> &nums) {
        int start = 0;
        int end = nums.size() - 1;
        while (end - start > 1) {
            if (nums[start] < nums[end]) {
                return nums[start];
            }
            int mid = (start + end) / 2;
            if (nums[start] < nums[mid]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return std::min(nums[start], nums[end]);
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << s.findMin(nums) << endl;
    return 0;
}
