// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    void inorder(vector<int>& ans, TreeNode* root) {
        if(root == NULL)
            return;
        ans.push_back(root->val);
        inorder(ans, root->left);
        inorder(ans, root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // inorder(ans, root);
        // return ans;
        vector<int> ans;
        if(root == NULL)
            return ans;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode *root = st.top();
            st.pop();

            ans.push_back(root->val);
            if(root->right)
                st.push(root->right);
            if(root->left)
                st.push(root->left);
        }
        return ans;
    }
};