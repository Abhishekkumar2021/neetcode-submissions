class Node {
   public:
    map<char, Node*> child;
    vector<string> suggestions;  // max 3 suggestions - lexicographically
    bool end;

    Node() : end(false) {}
};

class Solution {
   public:
    void insert(Node* root, const string& product) {
        Node* curr = root;

        for (char ch : product) {
            if (curr->child.find(ch) == curr->child.end()) {
                curr->child[ch] = new Node();
            }

            curr = curr->child[ch];

            if (curr->suggestions.size() < 3) {
                curr->suggestions.push_back(product);
            }
        }

        curr->end = true;
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        Node* root = new Node();

        for (const string& product : products) {
            insert(root, product);
        }

        vector<vector<string>> ans;
        Node* curr = root;

        for (char ch : searchWord) {
            if (curr != nullptr && curr->child.find(ch) != curr->child.end()) {
                curr = curr->child[ch];
                ans.push_back(curr->suggestions);
            } else {
                curr = nullptr;
                ans.push_back({});
            }
        }

        return ans;
    }
};