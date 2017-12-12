/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

/*
 * G(i) = i^ (i/2)
*/

#include "helper.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for (int i = 0; i < 1<<n; i++){
            result.push_back(i ^ i>>1);
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.grayCode(2) << endl;
    cout << s.grayCode(3) << endl;

    return 0;
}
