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
       TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = nullptr;
        if(inorder.size() >0){
        int preorder_root = 0;
        root = buildtree_from_preorder_inorder(inorder, preorder, 0, inorder.size()-1, preorder_root);
        }
        return root;
    }
private:
    TreeNode* buildtree_from_preorder_inorder(vector<int>& inorder, vector<int>& preorder, int idx_start, int idx_end, int& preorder_root){
        if(idx_end<idx_start){
            return nullptr;
        }
        TreeNode* root;
        int idx_root{preorder_root};
        root = new TreeNode(preorder.at(preorder_root));
        for(int i = idx_start; i<= idx_end; i++){
            if(inorder.at(i) == root->val){
                idx_root = i;
                break;
            }
        }
            // root node accessed from preorder vector
            // we can divide indexes inside the inorder vector
            // inorder LHS -> root -> RHS
            // find last LHS in inorder "endLHS"
            // call again on LHSrange of inorder
            // postorder (LHS1 -> RHS1 -> rootLHS1)   
        preorder_root++;
        root->left = buildtree_from_preorder_inorder(inorder, preorder, idx_start, idx_root-1,preorder_root);
        root->right = buildtree_from_preorder_inorder(inorder, preorder, idx_root+1, idx_end,preorder_root);
        return root;
    }
};

int main(){

vector<int> inorder = {9,3,15,20,7};
vector<int> preorder = {3,9,20,15,7};


TreeNode* dapreTree;
Solution mySol;
dapreTree = mySol.buildTree(inorder,preorder);
std::cout << "da Root "<< dapreTree->val << std::endl;
}