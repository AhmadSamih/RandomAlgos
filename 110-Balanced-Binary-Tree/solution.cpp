/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isB = true;
    int dfs(TreeNode* root, int depth){
        if(!root) return depth;
        
        int left = dfs(root->left, depth+1);
        int right = dfs(root->right, depth+1);
        
        if(abs(left-right)>1)
            isB=false;
        
        return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        
        dfs(root, 0);
        return isB;
    }
};