class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        vector<pair<int, int>> v;
        int n = p.size();

        for(int i=0; i<n; i++) {
            v.push_back({p[i], s[i]});
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        int ans = 0;
        double ahead = 0;

        for(int i=0; i<n; i++) {
            auto [pos, speed] = v[i];
            double t = (target - pos) * 1.0 / speed;

            if(t > ahead) {
                ans++;
                ahead = t;
            } 

        }

        return ans;

    }
};
