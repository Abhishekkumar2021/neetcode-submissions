class Solution {
public:

    std::string encode(std::vector<std::string>& strs) {
        std::string ans = "";

        for(auto &s: strs) {
            ans += std::to_string(s.length()) + "_" + s;
        }

        return ans;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> ans;

        int l = 0, i = 0, n = s.length();
        while(i < n) {
            if(s[i] == '_') {
                // First time dollar seen for the particular string
                ans.push_back(s.substr(i + 1, l));

                i += l + 1;
                l = 0;
            }

            l = l * 10 + (s[i] - '0');
            i++;
        }

        return ans;
    }
};