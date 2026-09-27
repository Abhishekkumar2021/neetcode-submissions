class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        map<int, int> mp;
        int ans = 0;

        for(auto &x: nums) {
            if(mp.find(x-1) != mp.end()) {
                // already a list exist, continue that
                mp[x] = mp[x-1] + 1;
            } else {
                mp[x] = 1;
            }

            ans = max(ans, mp[x]);
        }

        return ans;
    }
};
