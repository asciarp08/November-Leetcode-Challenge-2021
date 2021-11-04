/**
Time = O(n)
Space = O(n)
**/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
    
    void dfs(TreeNode* root, bool left, int& sum){
        if(root->left==NULL && root->right==NULL && left)
            sum+=root->val;
        
        if(root->left!=NULL)
            dfs(root->left, 1, sum);
        if(root->right!=NULL)
            dfs(root->right, 0, sum);
        
    }
};
