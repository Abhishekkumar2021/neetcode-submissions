class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size();
        vector<int> ind(n, 0);

        for(int i = 0; i < n; i++) {
            ind[fav[i]]++;
        }

        vector<int> len(n, 1);
        vector<bool> vis(n, false);

        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(ind[i] == 0) {
                q.push(i);
                vis[i] = true;
            }
        }

        // Topological sort + longest chain DP
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            int child = fav[node];

            len[child] = max(len[child], len[node] + 1);

            if(--ind[child] == 0) {
                q.push(child);
                vis[child] = true;
            }
        }

        int max_cycle = 0;
        int two_cycle_sum = 0;

        // Process remaining cycles
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int cycle_len = 1;

                vis[i] = true;
                int next = fav[i];

                while(next != i) {
                    cycle_len++;

                    vis[next] = true;
                    next = fav[next];
                }

                if(cycle_len == 2) {
                    two_cycle_sum += len[i] + len[fav[i]];
                }
                else {
                    max_cycle = max(max_cycle, cycle_len);
                }
            }
        }

        return max(max_cycle, two_cycle_sum);
    }
};