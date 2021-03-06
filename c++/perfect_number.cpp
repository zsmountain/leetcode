/*
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)

*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }
        int sum = 1;
        int upper = int(sqrt(num));
        for (int i = 2; i <= upper; i++) {
            if (num % i == 0) {
                sum += i + num / i;
            }
        }
        return sum == num;
    }
};

int main() {
    Solution s;
    cout << s.checkPerfectNumber(6) << endl;
    cout << s.checkPerfectNumber(28) << endl;
    cout << s.checkPerfectNumber(1) << endl;
    cout << s.checkPerfectNumber(100000000) << endl;
    return 0;
}
