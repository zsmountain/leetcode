/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0) {
            n--;
            res += char('A' + n % 26);
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    cout << s.convertToTitle(28) << endl;
    return 0;
}
