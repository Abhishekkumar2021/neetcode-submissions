class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<=n;i++){
            int ct=0;
            for(int x:nums){
                ct+=(x>=i);

            }
            if(ct==i) return ct;
        }
        return -1;
    }
};