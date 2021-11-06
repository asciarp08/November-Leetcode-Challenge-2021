/**
Time = O(n)
Space = O(1)
**/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a=0, b=0;
        long long totalXor = 0;
        
        for(auto num:nums){
            totalXor^=(long long)num;
        }
        
        long long mask = totalXor&(-totalXor);
        
        for(auto num:nums){
            if(mask&(long long)num){
                a^=num;
            }
            else
                b^=num;
        }
        
        return {a,b};
    }
};
