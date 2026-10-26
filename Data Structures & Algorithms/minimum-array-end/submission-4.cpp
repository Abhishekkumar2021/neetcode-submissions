class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int> ans(63, 0);
        int idx = 0;
        int x_copy = x;
        while(x > 0) {
            if(x % 2 == 1) ans[idx] = 1;
            idx++;

            x /= 2;
        }

        idx = 0;
        n--;

        if(n == 0) return x_copy;

        while(n > 0 && idx < 63) {
            while(idx < 63 && ans[idx] == 1) idx++;

            if(idx < 63 && n % 2 == 1) ans[idx] = 1;
            idx++;

            n /= 2;
        }

        long long res = 0;
        for(int i=0; i<63; i++) {
            if(ans[i] == 1) res |= (1LL << i);
        }

        return res;

    }
};