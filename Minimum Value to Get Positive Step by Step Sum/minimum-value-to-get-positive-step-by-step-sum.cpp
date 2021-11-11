/**
Time = O(n)
Space = O(1)
**/

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int totalSum = 0, startValue = INT_MAX;
        
        for(auto num:nums){
            totalSum+=num;
            startValue = min(startValue, totalSum);
        }
        return (startValue>=0?0:abs(startValue))+1;
    }
};
