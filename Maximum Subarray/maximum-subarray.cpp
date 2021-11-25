/**
Time = O(n)
Space = O(1)
**/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN, cur = nums[0];
        mx = cur;
        
        for(int i = 1; i<n; i++){
            cur = max(nums[i], cur+nums[i]);
            mx = max(mx, cur);
        }
        return mx;
    }
};
