/**
Time - O(n)
Space - O(h), h is less than or equal to 10 for this problem, we can say space complexity for this problem is O(1)
**/
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, root->val, sum);
        return sum;
    }
    
    void dfs(TreeNode* node, int curNum, int& sum){
        
        if(node->left==NULL && node->right==NULL){
            sum+=curNum;
            return;
        }
        if(node->left!=NULL){
            dfs(node->left, curNum*10+node->left->val, sum);
        }
        if(node->right!=NULL){
            dfs(node->right, curNum*10+node->right->val, sum);
        }
    }
};
