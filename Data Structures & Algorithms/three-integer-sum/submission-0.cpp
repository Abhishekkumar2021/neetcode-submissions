class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<=n-3; i++){
            int j = i + 1, k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    while(j < n-1 && nums[j+1] == nums[j]) j++;
                    j++;
                }
                else if(sum > 0){
                    while(k >= 1&& nums[k-1] == nums[k]) k--;
                    k--;
                }else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j < n-1 && nums[j+1] == nums[j]) j++;
                    j++;
                    while(k >= 1&& nums[k-1] == nums[k]) k--;
                    k--;
                }
            }
            while(i<n-1 && nums[i+1] == nums[i]) i++;
            
        }
        return ans;

    }
};
