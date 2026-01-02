class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size()/2;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]++;}
                else{
                    mp[nums[i]]++;
                }
                if(mp[nums[i]]==n){
                    return nums[i];
                }

            
        }
        return -1;
    }
};