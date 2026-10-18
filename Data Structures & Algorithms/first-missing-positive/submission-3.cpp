class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int ct=1;
        sort(nums.begin(), nums.end());
        int i=0;
        while(i<n && nums[i]<=0) i++;
        if(i==n) return 1;
        int ans=1;
        while(i<n){
            if(nums[i]>ans) return ans;
            else if(nums[i]==ans) ans++;
            i++;
        }
        return i==n?nums[n-1]+1:ans;
    }
};