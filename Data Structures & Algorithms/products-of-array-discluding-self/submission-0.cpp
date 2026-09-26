class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n, 1);
        for(int i=n-2; i>=0; i--) r[i] = r[i+1] * nums[i+1];
        int l = 1;
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(i>=1) l *= nums[i-1];
            ans.push_back(l*r[i]);
        }

        return ans;
    }
};
