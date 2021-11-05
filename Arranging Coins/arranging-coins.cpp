/**
Time = O(logn)
Space = O(1)
**/

class Solution {
public:
    int arrangeCoins(int n) {
        
        int l = 1, r= n;
        int ans;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            if((long long)mid*((long long)mid+1LL)/2LL<=(long long)n){
                ans = mid;
                l = mid+1;
            }
            else{
                r= mid-1;
            }
        }
        return ans;
    }
};
