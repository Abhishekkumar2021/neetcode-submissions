class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a, vector<int>& b) {
        map<int, int> mp;
        for(auto &x: a) mp[x]++;

        vector<int> ans;
        for(auto &x: b) {
            while(mp[x]--) ans.push_back(x);

            mp.erase(x);
        }

        for(auto &x: mp) {
            while(mp[x.first]--) ans.push_back(x.first);
        }

        return ans;
    }
};