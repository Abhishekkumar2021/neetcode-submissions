class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> s;
        int ans = 0;
        for(auto &c: op) {
            if(c == "D") {
                int a = s.top();
                s.push(2 * a);
            }
            else if(c == "C") {
                s.pop();
            }
            else if(c == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();

                s.push(a);

                s.push(a+b);
            } else {
                s.push(stoi(c));
            }
        }

        while(!s.empty()) {
            int a = s.top();
            ans += a;
            s.pop();
        }

        return ans;
    }
};