class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        int curr=0;
        for(auto x: nums){
            arr.push_back(curr+x);
            curr+=x;
        }
        int right=0;
        int ans=0;
        for(int i=n-1;i>=1;i--){
             right+=nums[i];
             curr-=nums[i];
             if(curr>=right) ans++;
        }
        return ans;
    }
};
