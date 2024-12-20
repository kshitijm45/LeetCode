// https://leetcode.com/problems/binary-tree-postorder-traversal

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
    void postorder(vector<int>& ans, TreeNode* root) {
        if(root == NULL)
            return;
        postorder(ans, root->left);
        postorder(ans, root->right);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        // postorder(ans, root);
        // return ans;
        if(root == NULL)
            return ans;
        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty()) {
            TreeNode *temp = st1.top();
            st1.pop();

            st2.push(temp);
            if(temp->left)
                st1.push(temp->left);
            if(temp->right)
                st1.push(temp->right);
        }
        while(!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};