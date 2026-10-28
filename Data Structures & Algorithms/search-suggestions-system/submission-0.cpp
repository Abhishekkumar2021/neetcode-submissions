class Node {
   public:
    char c;
    map<char, Node*> child;
    bool end;

    Node(char c = '#') : c(c), end(false) {}
};

class Solution {
   public:
    void insert(Node* root, string& s) {
        Node* curr = root;

        for (char ch : s) {
            if (curr->child.find(ch) == curr->child.end()) {
                curr->child[ch] = new Node(ch);
            }

            curr = curr->child[ch];
        }

        curr->end = true;
    }

    void dfs(Node* node, string& curr, vector<string>& result) {
        if (node == NULL || result.size() == 3) {
            return;
        }

        if (node->end) {
            result.push_back(curr);
        }

        for (auto& p : node->child) {
            curr.push_back(p.first);

            dfs(p.second, curr, result);

            curr.pop_back();

            if (result.size() == 3) {
                return;
            }
        }
    }

    vector<string> matched(Node* root, string& pre) {
        Node* curr = root;

        for (char ch : pre) {
            if (curr->child.find(ch) == curr->child.end()) {
                return {};
            }

            curr = curr->child[ch];
        }

        vector<string> result;
        string word = pre;

        dfs(curr, word, result);

        return result;
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        Node* root = new Node();

        for (auto& product : products) {
            insert(root, product);
        }

        string pre;

        for (char ch : searchWord) {
            pre.push_back(ch);
            ans.push_back(matched(root, pre));
        }

        return ans;
    }
};