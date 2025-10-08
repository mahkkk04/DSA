class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = numBottles;
        while (numBottles >= numExchange) {
            int newBottles = numBottles / numExchange;
            totalDrunk += newBottles;
            numBottles = numBottles % numExchange + newBottles;
        }
        return totalDrunk;
    }
};
