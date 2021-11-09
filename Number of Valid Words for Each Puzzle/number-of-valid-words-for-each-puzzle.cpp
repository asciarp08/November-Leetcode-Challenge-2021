/**
Time = O(m*(2^p)*plogp + n*wlogw) , m = puzzles.size(), p = puzzles[i].size(), n = words.size(), w = word[i].size()
Space = O(m*(2^p))
**/
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<string, unordered_map<int, bool>> vis; //subset, idx, true
        int m = puzzles.size();
        for(int i = 0; i<m ;i++){
            string pz = puzzles[i];
            char first = pz[0];
            for(int j = 0; j<(1<<6); j++){
                string s = "";
                for(int k = 0; k<6; k++){
                    if(j&(1<<k)){
                        s+=pz[k+1];
                    }
                }
                s = first+s;
                sort(s.begin(), s.end());
                vis[s][i] = 1;
            }
            
        }
        
        vector<int> ans(m, 0);
        for(auto word:words){
            set<char> chars;
            for(auto c:word){
                chars.insert(c);
            }
            
            if(chars.size()>7)
                continue;
            string s = "";
            for(auto c:chars){
                s+=c;
            }
            if(vis.count(s)){
                for(auto [idx,_]:vis[s]){
                    ans[idx]++;
                }
            }
        }
        return ans;
    }
};
