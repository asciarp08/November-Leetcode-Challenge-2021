/**
Time = O(n)
Space = O(1)
**/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n = temp.size();
        int maxTemp = 0;
        vector<int> wait(n,0);
        
        for(int i = n-1; i>=0; i--){
            if(temp[i]>=maxTemp){
                maxTemp = temp[i];
            }else{
                int days = 1;
                while(i+days<n && temp[i+days]<=temp[i]){
                    days+=wait[i+days];
                }
                wait[i] = days;
            }
        }
        return wait;
    }
};
