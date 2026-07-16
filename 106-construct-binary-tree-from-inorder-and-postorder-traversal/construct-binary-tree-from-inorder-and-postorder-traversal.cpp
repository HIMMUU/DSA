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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int > mpp ; 
        for( int i = 0 ; i < inorder.size() ; i++){
            mpp[inorder[i]] = i ;
        }
        return buildTree( inorder , 0 , inorder.size() - 1 , postorder , 0 , postorder.size()-1 , mpp );
    }
    TreeNode * buildTree( vector<int> &inorder , int is , int ie  , vector<int>&postorder , int ps , int pe , unordered_map<int, int>& mpp){
       if (is > ie || ps > pe)
    return NULL;
        
        TreeNode* node = new TreeNode(postorder[pe]);

        int inroot = mpp[node->val] ; 
        int numsleft =  inroot - is; 

        node->left = buildTree(inorder , is , inroot- 1 , postorder , ps , ps+numsleft - 1 , mpp);
        node->right = buildTree(inorder , inroot+1 , ie , postorder , ps+numsleft ,pe - 1 ,mpp);
        return node ; 

    }
};