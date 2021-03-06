/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist,
 return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
 */

/*
 *
*/

#include "helper.h"

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        for (int n:nums) {
            if (n > first) {
                third = second;
                second = first;
                first = n;
            } else if (n > second && n != first) {
                third = second;
                second = n;
            } else if (n >= third && n != first && n != second) {
                third = n;
            }
        }
        return third == LONG_MIN ? first : third;
    }
};

int main() {
    Solution s;
    vector<int> nums({1, 2, -2147483648});
    cout << s.thirdMax(nums) << endl;
    nums = {1, 2, 2, 5, 3, 5};
    cout << s.thirdMax(nums) << endl;

    return 0;
}
