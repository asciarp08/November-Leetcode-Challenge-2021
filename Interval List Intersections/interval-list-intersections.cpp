/**
Time = O(m+n)
Space = O(1)
**/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int n = A.size();
        int m = B.size();
        vector<vector<int>> res;
        int i = 0, j = 0;
        
        while(i<n && j<m){
            int lo = max(A[i][0], B[j][0]);
            int hi = min(A[i][1], B[j][1]);
            
            if(lo<=hi){
                res.push_back({lo,hi});
            }
            
            if(hi==A[i][1])i++;
            else j++;
        }
        
        return res;
        
    }
};
