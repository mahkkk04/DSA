class Solution {
public:
    // Trie node for 4 DNA characters
    struct Node {
        Node* child[4];
        int count;

        Node() {
            for(int i = 0; i < 4; i++) child[i] = NULL;
            count = 0;
        }
    };

    // Map DNA characters to indices
    unordered_map<char,int> mp = {
        {'A',0}, {'T',1}, {'G',2}, {'C',3}
    };

    Node* root = new Node();

    // Insert substring into trie and track repetition
    void insert(string &s, vector<string>& ans){
        Node* cur = root;

        for(int i = 0; i < 10; i++){
            int idx = mp[s[i]];

            // Create node if path doesn't exist
            if(!cur->child[idx])
                cur->child[idx] = new Node();

            cur = cur->child[idx];
        }

        // Increase frequency at leaf
        cur->count++;

        // Add only when seen second time
        if(cur->count == 2)
            ans.push_back(s);
    }

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;

        // Process every 10-length substring
        for(int i = 0; i + 9 < s.size(); i++){
            string sub = s.substr(i,10);
            insert(sub, ans);
        }

        return ans;
    }
};