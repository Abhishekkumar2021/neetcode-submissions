class Solution {
    vector<string> temp;
public:

    string encode(vector<string>& strs) {
        temp = strs;

        return "";
    }

    vector<string> decode(string s) {
        return temp;
    }
};
