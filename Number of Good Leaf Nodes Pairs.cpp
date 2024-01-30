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
public:
    int res;

    vector<int> helper(TreeNode * root,int distance){
        vector<int> ret(distance,0);
        if(!root)
            return ret;
        if(root->left==nullptr&&root->right==nullptr){
            ret[1]=1;
            return ret;
        }
        vector<int> left=helper(root->left,distance);
        vector<int> right=helper(root->right,distance);
        for(int i=1;i<distance;i++){
            for(int j=distance-i;j>=1;j--){
                res+=left[i]*right[j];
            }
        }
        for(int i=1;i<distance;i++)
            ret[i]=left[i-1]+right[i-1];
        return ret;
    }

    int countPairs(TreeNode* root, int distance) {
        if(distance==1)
            return 0;
        res=0;
        helper(root,distance);
        return res;
    }
};
