class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        vector<int> diff(n, 0);
        for(int i=0; i<n; i++) {
            int x = t[i] - s[i];
            if(s[i] > t[i]) x = s[i] - t[i];
            diff[i] = x;
        }

        int i=0, j = 0;
        int ans = 0;
        int sum = 0;
        while(j < n) {
            sum += diff[j];
            while(sum > maxCost) {
                sum -= diff[i];
                i++;
            }

            ans = max(ans, j - i + 1);

            j++;
        }

        return ans;

    }
};
