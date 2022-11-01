// Symmetric Tree
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// Follow up: Solve it both recursively and iteratively.

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTreetest
{
public:
    TreeNode *root;
    BinaryTreetest()
    {
        //     1
        //    / \
        //   2   2
        //  / \ / \
        // 3  4 4  3
        TreeNode *L1,*L2,*L3,*L4,*L5,*L6,*L7;
        L7 = new TreeNode(3,nullptr,nullptr);
        L6 = new TreeNode(4,nullptr,nullptr);
        L5 = new TreeNode(4,nullptr,nullptr);
        L4 = new TreeNode(3,nullptr,nullptr);
        L3 = new TreeNode(2,L6,L7);
        L2 = new TreeNode(2, L4, L5);
        L1 = new TreeNode(1,L2,L3);
        root = L1; // root(0);
    }
    BinaryTreetest(vector<int> input_tree_pre, vector<int> input_tree_post)
    {
        // call a private method to create the tree from the list (can use the )
    }
    ~BinaryTreetest()
    {
        //traverse tree in [postorder way to delete all nodes
    }
};

class Solution_iterative
{
public:
    bool is_symmetric(TreeNode* root) {
        queue<TreeNode*> Tree_LHS;
        queue<TreeNode*> Tree_RHS;
        if (root)
        { // if root is null, will simply return empty output
            Tree_LHS.push(root->left);
            Tree_RHS.push(root->right);
        }

        TreeNode *left_node, *right_node;
        while (!Tree_LHS.empty())
        {

            int level_size = Tree_LHS.size()-1;
            for( int i = 0; i <= level_size; i++ ){     //process nodes on current level from LIFO queue
                left_node = Tree_LHS.front();     
                Tree_LHS.pop();
                right_node = Tree_RHS.front();     
                Tree_RHS.pop();
                if((left_node==nullptr) && (right_node==nullptr)){
                    continue;     //case 1: both are nullptr, then is consistent but we dont push any more values
                }

                if( (left_node == nullptr) !=  (right_node == nullptr) ){  //case 2: XOR if one is nullptr means non symmetric
                   return false;
               }

               if(left_node->val != right_node->val){
                    return false;                       // case3: if values do not match, is not symmetric
                }
                Tree_LHS.push(left_node->left);         // push all values in order
                Tree_RHS.push(right_node->right);
                Tree_LHS.push(left_node->right); 
                Tree_RHS.push(right_node->left);
                }
            }
        return true;  // if we made it to the end, then the whole tree is symmetric
    }
};

class recursive_symmetry_test
{
public:
    bool symmetry_test(TreeNode* root){
      if(root==nullptr){
        return true;
      }
      return test_symmetry(root,root);
    }
private: 
  bool test_symmetry(TreeNode* LeftNode, TreeNode* RightNode){
      if((LeftNode==nullptr) && (RightNode==nullptr)){
          return true;     //case 1: both are nullptr, then is consistent 
      }
      if((LeftNode==nullptr) || (RightNode==nullptr)){
          return false;  // case 2: node structures are different
      }
      if(LeftNode->val != RightNode->val){
          return false; // case 3: values of symmetric nodes are different
      }
      if(!test_symmetry(LeftNode->right, RightNode->left) || !test_symmetry(RightNode->left, LeftNode->right )){
          return false;  //recursion through the rest of the tree until nullptr indicates end
      }
      return true;
    }

};

void print_test( const vector<vector<int>>& output){
        for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output.at(i).size(); j++){
            std::cout << output.at(i).at(j)<< "  ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    BinaryTreetest test1;

    Solution_iterative sol_it;
    bool symmetry = sol_it.is_symmetric(test1.root);
    //std::cout << "isSymmetric = " << symmetry << endl; 
    recursive_symmetry_test recursive;
    bool rec_symm = recursive.symmetry_test(test1.root);
    std::cout << "isSymmetric = " << rec_symm << endl;
}