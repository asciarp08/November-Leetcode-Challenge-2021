/**
Time = O(n*n)
Space = O(n)
**/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        int mx = 0, idx = 0;
        for(int i = 0; i<n; i++){
            dp[i][1] = -1;
        }
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[j]%nums[i]==0){
                    if(dp[j][0]<dp[i][0]+1){
                        dp[j][0] = dp[i][0]+1;
                        dp[j][1] = i;
                        if(mx<dp[j][0]){
                            mx = dp[j][0];
                            idx = j;
                        }
                    }
                }
            }
        }
        vector<int> ans;
        while(idx!=-1){
            ans.push_back(nums[idx]);
            idx = dp[idx][1];
            
        }
        
        return ans;
    }
};
