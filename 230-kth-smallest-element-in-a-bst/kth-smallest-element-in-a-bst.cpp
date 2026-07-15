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
    void  tra( TreeNode * root , int &k  , int &ans   ){
      if( root == NULL ) return ; 
    
         tra( root->left  ,k , ans);
        
         k--;
         if( k == 0 )  ans = root->val ;
        tra ( root->right , k ,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
   
   int ans = 0 ;
      tra(root  , k ,ans  );
      return  ans; 
      

    }
};