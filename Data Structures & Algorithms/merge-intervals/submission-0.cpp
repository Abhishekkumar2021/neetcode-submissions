class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(), in.end());

        int l = in[0][0], r = in[0][1], n = in.size();

        vector<vector<int>> ans;

        for(int i=1; i<n; i++) {
            if(in[i][0] > r) {
                ans.push_back({l, r});
                l = in[i][0];
                r = in[i][1];
            } else r = max(r, in[i][1]);
        }

        ans.push_back({l, r});

        return ans;
    }
};
