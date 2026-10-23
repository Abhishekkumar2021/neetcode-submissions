
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        stringstream ss1(s1), ss2(s2);
        vector<string> a, b;
        string word;

        while (ss1 >> word) a.push_back(word);
        while (ss2 >> word) b.push_back(word);

        if (a.size() < b.size()) swap(a, b);

        int i = 0, j = 0;
        int n = a.size(), m = b.size();

        // Match common prefix
        while (i < m && a[i] == b[i]) i++;

        // Match common suffix
        while (j < m && a[n - 1 - j] == b[m - 1 - j]) j++;

        return i + j >= m;
    }
};
