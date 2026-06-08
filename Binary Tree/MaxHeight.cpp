#include<iostream>
using namespace std 
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  public:
  int h( Node* root){
      if( root == NULL){
            return  0  ;
            
        }
        int left_height = h(root->left); 
        int right_height = h(root->right); 
        
       int ans = max(left_height , right_height)  + 1;
        return ans ;
  }
    int height(Node* root) {
        // code here
        int ans = h( root);
        return ans - 1;
    }
};