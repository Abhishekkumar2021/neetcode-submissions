class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> pre(n, 0);
        int cnt = 0;

        for(int i=0; i<n; i++) {
            if(i != 0) pre[i] = pre[i-1] + cnt;

            if(boxes[i] == '1') cnt++;
        }

        vector<int> ans(n, 0);

        int post = 0;
        
        cnt = 0;
        for(int i=n-1; i>=0; i--) {
            if(i != n-1) post = post + cnt;

            if(boxes[i] == '1') cnt++;

            ans[i] = pre[i] + post;
        }

        return ans;


    }
};