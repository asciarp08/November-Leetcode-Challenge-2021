/**
Complexity Analysis:
Time = O(n*(2^n)); n = characters.size()
Space = O(1)
**/
class CombinationIterator {
private: 
    int comb = 0, l = 0, len = 0;
    string chars;
public:
    CombinationIterator(string characters, int combinationLength) {
        len = characters.size();
        l = combinationLength;
        comb = (1<<len)-1;
        chars = characters;
    }
    
    string next() {
        while(comb>=0 && __builtin_popcount(comb)!=l)comb--;
        string cur = "";
        for(int i = 0; i<len; i++){
            if(comb&(1<<i))
                cur+=chars[len-1-i];
        }
        reverse(cur.begin(), cur.end());
        comb--;
        return cur;
    }
    
    bool hasNext() {
        while(comb>=0 && __builtin_popcount(comb)!=l)comb--;
        if(comb>0)
            return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
