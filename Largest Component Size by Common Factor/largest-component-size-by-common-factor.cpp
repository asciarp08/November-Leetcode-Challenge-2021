/**
Time = O(n*sqrt(m)); n = nums.size(), m = max(nums[i])
Space = O(m)
**/

class Solution {

struct UnionFindTree{
    vector<int> par, sz;
    UnionFindTree(int n){
        par.resize(n+1);
        sz.resize(n+1);
        for(int i = 1; i<=n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }
    
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y)return;
        if(sz[y]>sz[x])swap(x,y);
        sz[x]+=sz[y];
        par[y] = par[x];
    }
    
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
};
public:
    int largestComponentSize(vector<int>& nums) {
        const int mx = 100002;
        UnionFindTree dsu(mx);
        
        for(auto num:nums){
            for(int i = 2; i*i<=num; i++){
                if(num%i==0){
                    dsu.unite(num, i);
                    dsu.unite(num, num/i);
                }
            }
        }
        
        unordered_map<int,int>cnt;
        int ans = 1;
        
        for(auto num:nums){
            ans = max(ans, ++cnt[dsu.find(num)]);
        }
        return ans;
    }
};
