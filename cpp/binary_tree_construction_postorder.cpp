//construct binary trees

// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = nullptr;
        if(inorder.size() >0){
        int postorder_root = inorder.size()-1;
        root = construct_tree_from_root(inorder, postorder, 0, inorder.size()-1, postorder_root);
        }
        return root;
    }
private:
    TreeNode* construct_tree_from_root(vector<int>& inorder, vector<int>& postorder, int idx_start, int idx_end, int& postorder_root){
        if(idx_end<idx_start){
            return nullptr;
        }
        TreeNode* root;
        int idx_root{postorder_root};
        root = new TreeNode(postorder.at(postorder_root));
        for(int i = idx_start; i<= idx_end; i++){
            if(inorder.at(i) == root->val){
                idx_root = i;
                break;
            }
        }
            // root node accessed from postorder vector, then we can divide indexes inside inorder vector
            // inorder LHS -> root -> RHS
            // find last LHS in inorder "endLHS"
            // call again on LHSrange of inorder
            // postorder (LHS1 -> RHS1 -> rootLHS1)   
        postorder_root--;
        root->right = construct_tree_from_root(inorder, postorder, idx_root+1, idx_end,postorder_root);
        root->left = construct_tree_from_root(inorder, postorder, idx_start, idx_root-1,postorder_root);
        
        return root;
    }
};

int main(){

vector<int> inorder = {9,3,15,20,7};
vector<int> postorder = {9,15,7,20,3};

// vector<int> inorder = {9};  // simple root only case
// vector<int> postorder = {9};

Solution mysol;

TreeNode* daTree;
daTree = mysol.buildTree(inorder, postorder);
std::cout << "da Root "<< daTree->val << std::endl;
}