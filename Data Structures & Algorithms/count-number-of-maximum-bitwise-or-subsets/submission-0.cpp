class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int max_or = 0;
        for(auto &x: nums) max_or |= x;

        int ans = 0;

        for(int s=0; s < (1 << n); s++) {
            int curr_or = 0;
            for(int i=0; i<n; i++) {
                if((s >> i) & 1) curr_or |= nums[i];
            }

            if(curr_or == max_or) ans++;
        }

        return ans;
    }
};
