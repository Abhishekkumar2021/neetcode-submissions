class Solution {
public:
    int numOfMinutes(int n, int h, vector<int>& ma, vector<int>& in) {
        int ans = 0;
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            if(ma[i] != -1) adj[ma[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({h, 0});

        while(!q.empty()) {
            auto [node, reach] = q.front();
            q.pop();

            ans = max(ans, reach);

            for(auto &ch: adj[node]) {
                q.push({ch, reach + in[node]});
            }
        }

        return ans;
    }
};
