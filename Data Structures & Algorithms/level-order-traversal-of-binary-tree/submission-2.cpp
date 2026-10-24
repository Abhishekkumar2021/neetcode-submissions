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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> x;
            while(n--) {
                auto f = q.front();
                q.pop();
                x.push_back(f->val);

                if(f->left != NULL) q.push(f->left);
                if(f->right != NULL) q.push(f->right);
            }

            ans.push_back(x);
        }

        return ans;
    }
};
