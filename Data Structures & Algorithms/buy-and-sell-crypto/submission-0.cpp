class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, m = INT_MAX;
        for(auto &p: prices) {
            m = min(m, p);
            ans = max(ans, p - m);
        }

        return ans;
    }
};
