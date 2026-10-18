class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // 2, 0, 3, 4, 5, 0, 7 -> 
        vector<int> v;
        for(auto &s: bank) {
            int ct = 0;
            for(auto &ch: s) {
                if(ch == '1') ct++;
            }
            if(ct != 0) v.push_back(ct);
        }

        int ans = 0;
        int n = v.size();
        for(int i=1; i<n; i++) ans += v[i] * v[i-1];

        return ans;
    }
};
