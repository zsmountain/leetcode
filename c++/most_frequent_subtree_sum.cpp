/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as
 the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the
 most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.


 */

/*
 *
*/

#include "helper.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        unordered_map<int, int> map;
        int maxCount = 0;
        vector<int> res;
        getSum(root, map, maxCount);

        for (auto &it:map) {
            if (it.second == maxCount) {
                res.push_back(it.first);
            }
        }
        return res;
    }

    int getSum(TreeNode *root, unordered_map<int, int> &map, int &maxCount) {
        if (!root) {
            return 0;
        }
        int sum = root->val + getSum(root->left, map, maxCount) + getSum(root->right, map, maxCount);
        map[sum]++;
        maxCount = max(map[sum], maxCount);
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> preorder({5, 2, -5}), inorder({2, 5, -5});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.findFrequentTreeSum(root) << endl;

    return 0;
}
