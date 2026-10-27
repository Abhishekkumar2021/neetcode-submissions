
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());

        int n = nums.size(), ans = 0;
        vector<int> pow_mod(n, 1);

        for (int i = 1; i < n; i++) {
            pow_mod[i] = (2LL * pow_mod[i - 1]) % MOD;
        }

        for (int i = 0; i < n; i++) {
            int l = i, r = n - 1;

            while (l <= r) {
                int m = l + (r-l) / 2;

                if (nums[i] + nums[m] <= target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            if (r >= i) {
                ans = (ans + pow_mod[r - i]) % MOD;
            }
        }

        return ans;
    }
};
