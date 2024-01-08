/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> rec(TreeNode* root,int &ans){          
        if(root==NULL){
            return {0,INT_MAX,INT_MIN};           
        }
        vector<int> l=rec(root->left,ans);
        vector<int> r=rec(root->right,ans);
        
        if(l[2]<root->val && r[1]>root->val){       
            ans=max(ans,root->val+l[0]+r[0]);          
            return {root->val+l[0]+r[0],
                    min(root->val,l[1]),              
                    max(root->val,r[2])               
                   };
        }
        else{
            return {0,INT_MIN,INT_MAX};        
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        int ans=0;
        rec(root,ans);
        return ans;
    }
};
