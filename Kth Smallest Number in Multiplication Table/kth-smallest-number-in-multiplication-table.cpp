/**
Time = O(log(m*n))
Space = O(1)
**/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m*n;
        int ans = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            int count = smaller(m,n,mid);
            // cout << count << " " << k << endl;
            if(count>=k){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    
    
    int smaller(int m, int n, int x){
        int count = 0;
        for(int i = 1; i<=m; i++){
            count+=min(x/i, n);
        }
        return count;
    }
};
