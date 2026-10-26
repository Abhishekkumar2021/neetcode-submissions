class Solution {
public:
    int xorAllNums(vector<int>& a, vector<int>& b) {
        int ax = 0, bx = 0;

        for(auto &x: a) ax ^= x;
        for(auto &x: b) bx ^= x;

        int n = a.size(), m = b.size();

        int ans = 0;

        if(n % 2 == 1) ans ^= bx;
        if(m % 2 == 1) ans ^= ax;

        return ans;
    }
};
