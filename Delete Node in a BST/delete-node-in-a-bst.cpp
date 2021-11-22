/**
Time = O(logn)
Space = O(logn)
**/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)return root;
        
        if(root->val>key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val<key){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(root->left==NULL)return root->right;
            else if(root->right==NULL)return root->left;
            
            root->val = findMin(root->right)->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
    
    TreeNode* findMin(TreeNode* root){
        if(root->left!=NULL)return findMin(root->left);
        return root;
    }
};
