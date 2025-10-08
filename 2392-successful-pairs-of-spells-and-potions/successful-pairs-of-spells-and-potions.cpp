#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        std::vector<int> result;
        int potionCount = potions.size();
        std::sort(potions.begin(), potions.end());
        for (int spellStrength : spells) {
            long long minPotionStrength = (success + spellStrength - 1) / spellStrength;
            int firstValidIndex = std::lower_bound(potions.begin(), potions.end(), minPotionStrength) - potions.begin();
            result.push_back(potionCount - firstValidIndex);
        }
        
        return result;
    }
};
