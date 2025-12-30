class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;int maxlen=0;
        unordered_set<char>seen;
        for(int right=0;right<s.size();right++){
            while(seen.find(s[right])!=seen.end()){
                seen.erase(s[left]);
                left++;
        }
        seen.insert(s[right]);
        maxlen=max(maxlen,right-left+1);
    }
    return maxlen;
    }
};