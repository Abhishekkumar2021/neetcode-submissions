class Solution {
public:
    void f(int i, int n, int k, vector<int> &curr, vector<vector<int>> &ans) {
        if(k == 0) {
            ans.push_back(curr);
            return;
        }

        if(i > n) return;

        // take
        curr.push_back(i);
        f(i+1, n, k-1, curr, ans);

        curr.pop_back();
        f(i+1, n, k, curr, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<vector<int>> ans;

        f(1, n, k, curr, ans);

        return ans;
    }
};