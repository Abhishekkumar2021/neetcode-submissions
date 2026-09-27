class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> w;
        int l = 0, r = 0, ans = 0, n = s.size();
        while(r < n) {
            while(w.find(s[r]) != w.end()) {
                w.erase(s[l]);
                l++;
            }

            w.insert(s[r]);
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
