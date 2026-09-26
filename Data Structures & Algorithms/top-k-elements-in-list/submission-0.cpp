class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> f(2001, 0);
        for(auto &x: nums) f[x+1000]++;

        priority_queue<pair<int, int>> q;

        for(int i=0; i<=2000; i++) {
            if(f[i]) q.push({f[i], i-1000});
        }

        vector<int> ans;

        while(k--) {
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};
