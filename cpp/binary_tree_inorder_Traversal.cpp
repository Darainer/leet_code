// binary_tree_inorder_Traversal
// Given a binary tree, return the inorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [1,3,2]
// Follow up: Recursive solution is trivial, could you do it iteratively?


#include <vector>
#include <stack>
#include <iostream>

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

enum class tree_array_format
{
    DFS_preorder,
    DFS_postorder,
    DFS_inorder,
    BFS
};

class BinaryTreetest
{
public:
    TreeNode *root;
    BinaryTreetest()
    {
        TreeNode *L1;
        TreeNode *L2;
        L2 = new TreeNode(3);
        L1 = new TreeNode(2, L2, nullptr);
        root = new TreeNode(1, nullptr, L1); // root(0);
    }
    BinaryTreetest(vector<int> input_tree, tree_array_format tree_format)
    {
        // call a private method to create the tree from the list
    }
    ~BinaryTreetest()
    {
        //traverse tree in [postorder way to delete all nodes...smart_pointers instead?
    }
};

class Solution_iterative
{
public:
    vector<int> inOrderTraversal(TreeNode *root)
    {
        vector<int> output;
        stack<TreeNode*> node_stack;
        TreeNode *working_node = root;
        while (!node_stack.empty() || working_node!=nullptr)
        {
            while(working_node!=nullptr){               //traverse the left side
                node_stack.push(working_node);
                working_node = working_node->left;
            }
            working_node = node_stack.top();     //take from LIFO stack
            node_stack.pop();
            output.push_back(working_node->val);
            working_node = working_node->right;
        }
        return output;
    }
};

class Solution_recursive
{
public:
    vector<int> inOrderTraversal(TreeNode *root)
    {
        vector<int> tree_list{};
        if (root != nullptr)
        {
            add_value(root, tree_list);
        }
        return tree_list;
    }

private:
    void add_value(TreeNode *node, vector<int> &tree_list)
    {
        if (node->left != nullptr){
            add_value(node->left, tree_list);
        }
        tree_list.push_back(node->val);
        if (node->right != nullptr){
            add_value(node->right, tree_list);
        }

    }
};

int main()
{
    TreeNode *Root_node;

    BinaryTreetest test1;

    Solution_recursive sol_rec;
    vector<int> output = sol_rec.inOrderTraversal(test1.root);
    for (int i = 0; i < output.size(); i++)
    {
        std::cout << output.at(i) << std::endl;
    }

    Solution_iterative sol_it;
    vector<int> output_iterative = sol_it.inOrderTraversal(test1.root);
    for (int i = 0; i < output.size(); i++)
    {
        std::cout << output.at(i) << std::endl;
    }
}