/*
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value.
 And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
*/

/*
 *
 */

#include "helper.h"

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int res = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            res = max(res, sum);
        }
        return double(res) / k;
    }
};

int main() {
    Solution s;
    vector<int> nums({1, 12, -5, -6, 50, 3});
    cout << s.findMaxAverage(nums, 4) << endl;
    return 0;
}
