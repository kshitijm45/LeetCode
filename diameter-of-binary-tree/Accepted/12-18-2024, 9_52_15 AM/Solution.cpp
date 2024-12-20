// https://leetcode.com/problems/diameter-of-binary-tree

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
    pair<int, int> findDiam(TreeNode* root) {
        if(root == NULL)
            return {0,0};

        pair<int, int> left = findDiam(root->left);
        pair<int, int> right = findDiam(root->right);

        pair<int, int> ans;
        ans.first = max(left.first, max(right.first, left.second + right.second));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return findDiam(root).first;
    }
};