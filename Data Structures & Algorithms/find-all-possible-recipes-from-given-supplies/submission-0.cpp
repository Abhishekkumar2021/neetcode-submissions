class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        map<string, vector<string>> g;
        map<string, int> ind;
        set<string> available(sup.begin(), sup.end());

        int n = rec.size();

        for (int i = 0; i < n; i++) {
            ind[rec[i]] = ing[i].size();

            for (auto &x : ing[i]) {
                g[x].push_back(rec[i]);
            }
        }

        queue<string> q;
        for (auto &x : sup) q.push(x);

        vector<string> ans;

        while (!q.empty()) {
            string x = q.front();
            q.pop();

            for (auto &ch : g[x]) {
                if (--ind[ch] == 0) {
                    ans.push_back(ch);
                    q.push(ch);
                }
            }
        }

        return ans;
    }
};