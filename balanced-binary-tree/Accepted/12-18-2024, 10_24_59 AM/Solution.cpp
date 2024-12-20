// https://leetcode.com/problems/balanced-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<bool, int> findBal(TreeNode* root) {
        if(root == NULL)
            return {true, 0};

        pair<bool, int> left = findBal(root->left);
        pair<bool, int> right = findBal(root->right);

        pair<bool, int> ans;
        ans.first = left.first & right.first & (abs(left.second - right.second) <= 1);
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return findBal(root).first;
    }
};