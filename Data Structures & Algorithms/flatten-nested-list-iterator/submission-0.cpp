class NestedIterator {
    int m, idx;
    vector<int> l;
public:
    void dfs(int idx, int n, vector<NestedInteger>& nl, vector<int> &l) {
        if(idx == n) return;

        if(nl[idx].isInteger()) l.push_back(nl[idx].getInteger());
        else {
            vector<NestedInteger> temp_nl = nl[idx].getList();
            int m = temp_nl.size();
            vector<int> temp;
            dfs(0, m, temp_nl, temp);
            for(auto &x: temp) l.push_back(x);
        }

        dfs(idx+1, n, nl, l);

    }
    NestedIterator(vector<NestedInteger>& nl) {
        int n = nl.size();
        dfs(0, n, nl, l);

        m = l.size();
        idx = 0;
    }
    int next() {
        return l[idx++];
    }
    bool hasNext() {
        return idx < m;
    }
};
