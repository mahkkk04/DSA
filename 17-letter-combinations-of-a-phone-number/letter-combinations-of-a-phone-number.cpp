class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> mapping = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result = {""};

        for (char d : digits) {
            vector<string> temp;
            for (auto &s : result)
                for (char ch : mapping[d-'0'])
                    temp.push_back(s + ch);
            swap(result, temp);
        }

        return result;
    }
};
