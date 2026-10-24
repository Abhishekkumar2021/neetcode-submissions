class Solution {
public:
    int numberOfSubstrings(string s) {
        bool a = false, b = false, c = false;

        int i = 0, j = 0, n = s.size();
        map<char, int> mp;

        int ans = 0;

        while(j < n) {
            char ch = s[j];
            mp[ch]++;

            if(ch == 'a') a = true;
            if(ch == 'b') b = true;
            if(ch == 'c') c = true;

            while(a && b && c) {
                ans += n-j;

                mp[s[i]]--;

                if(s[i] == 'a' && mp[s[i]] == 0) a = false;
                if(s[i] == 'b' && mp[s[i]] == 0) b = false;
                if(s[i] == 'c' && mp[s[i]] == 0) c = false;

                i++;
            }

            j++;
        }

        return ans;
    }
};
