/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        TreeNode* root =
            buildtree(preorder, 0, preorder.size() - 1, inorder, 0,  inorder.size() - 1, mpp);
        return root;
    }
    TreeNode* buildtree(vector<int> &preorder, int ps, int pe,
                        vector<int> &inorder, int is, int ie,
                        map<int, int>& mpp) {
        if (ps > pe || is > ie)
            return NULL;
        TreeNode* node = new TreeNode(preorder[ps]);
        int ir = mpp[node->val];
        int numleft = ir - is;
        node->left = buildtree(preorder, ps + 1, ps + numleft, inorder, is,
                               ir - 1, mpp);
        node->right =
            buildtree(preorder, ps + 1 + numleft, pe, inorder, ir + 1, ie, mpp);
        return node;
    }
};