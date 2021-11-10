/**
Time = O(n)
Space = O(1)
**/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        for(auto p:prices){
            if(p<buy){
                buy = p;
            }
            else{
                profit += (p-buy);
                buy = p;
            }
        }
        return profit;
    }
};
