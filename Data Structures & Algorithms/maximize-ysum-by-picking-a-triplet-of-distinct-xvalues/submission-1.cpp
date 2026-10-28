class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        map<int, int> mp;
        int n = x.size();

        for(int i=0; i<n; i++) {
            mp[x[i]] = max(mp[x[i]], y[i]);
        }

        if (mp.size() < 3) return -1;

        priority_queue<int, vector<int>, greater<int>> q;
        for(auto &p: mp) {
            q.push(p.second);
            if(q.size() > 3) q.pop();
        }

        int ans = 0;
        while(!q.empty()) {
            ans += q.top();
            q.pop();
        }

        return ans;
    }
};