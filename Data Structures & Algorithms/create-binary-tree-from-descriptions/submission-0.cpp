class Solution {
public:
    TreeNode* dfs(int root, map<int, vector<pair<int, bool>>>& child) {
        TreeNode* node = new TreeNode(root);

        for(auto &c: child[root]) {
            int n = c.first;
            bool isLeft = c.second;

            if(isLeft) node->left = dfs(n, child);
            else node->right = dfs(n, child);
        }

        return node;
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, int> par;
        map<int, vector<pair<int, bool>>> child;
        set<int> nodes;

        for(auto &d: descriptions) {
            int p = d[0], n = d[1], isLeft = d[2];

            par[n] = p;
            child[p].push_back({n, isLeft});

            nodes.insert(p);
            nodes.insert(n);
        }

        int root = -1;
        for(auto &n: nodes) {
            if(par.find(n) == par.end()) root = n;
        }

        return dfs(root, child);
    }
};