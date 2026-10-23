class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        vector<pair<int, int>> v;
        int n = p.size();

        for (int i = 0; i < n; i++) {
            v.push_back({p[i], s[i]});
        }

        sort(v.rbegin(), v.rend());

        int ans = 0;
        double ahead = 0;

        for (auto [pos, speed] : v) {
            double t = (target - pos) * 1.0 / speed;

            if (t > ahead) {
                ans++;
                ahead = t;
            }
        }

        return ans;
    }
};