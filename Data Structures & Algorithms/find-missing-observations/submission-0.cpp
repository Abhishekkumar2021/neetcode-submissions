class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=(m+n)*mean;
        for(auto x: rolls){
            sum-=x;
        }
        vector<int>ans;
        if(sum<n || sum>6*n) return ans;
        ans.resize(n, 6);
        int big=6*n;
        int i=0;
        while(big>sum){
            ans[i]--;
            i++;
            big--;
            if(i==n) i=0;
        }
        return ans;
        
    }
};
