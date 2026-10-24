class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int s = servers.size(), t = tasks.size();
        vector<int> ans;

        using pii = pair<int, int>;
        using pli = pair<long long, int>;

        priority_queue<pii, vector<pii>, greater<pii>> available;
        priority_queue<pli, vector<pli>, greater<pli>> busy;

        for (int i = 0; i < s; ++i)
            available.push({servers[i], i});

        auto freeServers = [&](long long time) {
            while (!busy.empty() && busy.top().first <= time) {
                auto [endTime, index] = busy.top();
                busy.pop();
                available.push({servers[index], index});
            }
        };

        long long time = 0;

        for (int i = 0; i < t; ++i) {
            time = max(time, static_cast<long long>(i));
            freeServers(time);

            if (available.empty()) {
                time = busy.top().first;
                freeServers(time);
            }

            int index = available.top().second;
            available.pop();

            ans.push_back(index);
            busy.push({time + tasks[i], index});
        }

        return ans;
    }
};