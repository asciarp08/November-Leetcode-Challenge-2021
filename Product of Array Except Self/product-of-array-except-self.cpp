/**
Time = O(n)
Space = O(1)
**/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int preProduct = 1;
        vector<int>res(n);
        res[n-1] = nums[n-1];
        
        for(int i = n-2; i>=0; i--){
            res[i] = nums[i]*res[i+1];
        }
        
        for(int i = 0; i<n; i++){
            res[i] = preProduct*(i<n-1?res[i+1]:1);
            preProduct*=nums[i];
        }
        return res;
    }
};
