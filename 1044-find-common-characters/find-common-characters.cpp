class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26, INT_MAX);
        for(string &w : words) {
            vector<int> tmp(26,0);
            for(char c : w) tmp[c-'a']++;
            for(int i=0;i<26;i++) freq[i] = min(freq[i], tmp[i]);
        }
        vector<string> ans;
        for(int i=0;i<26;i++) {
            while(freq[i]--) ans.push_back(string(1, i+'a'));
        }
        return ans;
    }
};
