class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size();
        while (i < n - 1) {
            if (bits[i] == 1) 
                i += 2;   // skip a 2-bit character
            else 
                i += 1;   // skip a 1-bit character
        }
        return i == n - 1;  // true only if we ended exactly at last bit
    }
};
