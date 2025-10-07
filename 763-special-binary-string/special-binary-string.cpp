class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> subs;
        int count=0,start=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='1') count++;
            else count--;
            if (count==0) {
                string inner = s.substr(start+1,i-start-1);
                subs.push_back("1"+makeLargestSpecial(inner)+"0");
                start=i+1;
            }
        }
        sort(subs.begin(),subs.end(),greater<string>());
        string res;
        for (auto &x:subs) res+=x;
        return res;
    }
};
