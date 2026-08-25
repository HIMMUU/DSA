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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if( root == NULL ) return new TreeNode  (val);
       TreeNode * temp = root ; 
        TreeNode * temp2 = NULL ;
        while( temp != NULL ){
           temp2 = temp ; 
            if( temp->val < val ){
                temp = temp->right;
            }
            else  temp = temp->left; 

        }
        TreeNode *ans = new TreeNode(val );
        if( temp2->val > val  )
        temp2->left = ans;
        else temp2->right = ans ; 

        return root ; 
    }
};