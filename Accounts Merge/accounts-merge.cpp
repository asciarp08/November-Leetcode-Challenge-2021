/**
Time = O(n*m*k); n = accounts.size(), m = accounts[i].size(), k = accounts[i][j].size()
Space = O(nmklog(nmk))
**/

class Solution {
    struct UnionFindTree{
        vector<int> par, sz;
        UnionFindTree(int n){
            par.resize(n);
            sz.resize(n);
            for(int i = 0; i<n; i++){
                par[i] = i;
                sz[i] = 1;
            }
        }
        
        void unite(int x, int y){
            x = find(x), y = find(y);
            
            if(x==y)return;
            if(sz[x]<sz[y])swap(x,y);
            sz[x]+=sz[y];
            par[y] = x;
        }
        
        int find(int x){
            return x==par[x]?x:par[x]=find(par[x]);
        }
        
        
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFindTree dsu(n);
        
        unordered_map<string, int> mailId;
        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size();j++){
                if(mailId.count(accounts[i][j])){
                    dsu.unite(i, mailId[accounts[i][j]]);
                }
                else{
                    mailId[accounts[i][j]] = i;
                }
            }
        }
        
        unordered_map<int, set<string>> mergedAccounts;
        for(auto [mail, id]:mailId){
            mergedAccounts[dsu.find(id)].insert(mail);
        }
        
        vector<vector<string>> res;
        for(auto [id, mails]:mergedAccounts){
            vector<string> tmp;
            tmp.push_back(accounts[id][0]);
            for(auto mail:mails){
                tmp.push_back(mail);
            }
            res.push_back(tmp);
        }
        return res;
            
            
            
            
    }
};
