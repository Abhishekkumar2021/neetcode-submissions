class Solution {
public:
    int shortest_distance(int src, int dest, vector<vector<int>> &adj) {
        const int inf = 1e9;
        int n = adj.size();

        vector<int> dist(n, inf);

        using pi = pair<int, int>;
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            auto [d, n] = pq.top();
            pq.pop();

            for(auto &ch: adj[n]) {
                if(dist[ch] > d + 1) {
                    dist[ch] = d + 1;
                    pq.push({d + 1, ch});
                }
            }
        }

        return dist[dest];

    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;

        vector<vector<int>> adj(n);

        for(int i=1; i<n; i++) {
            adj[i-1].push_back(i);
        }

        for(auto &q: queries) {
            // update graph
            int u = q[0], v = q[1];
            adj[u].push_back(v);

            ans.push_back(shortest_distance(0, n-1, adj));
        }

        return ans;
    }
};
