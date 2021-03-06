// binary_tree_preorder_Traversal

// Given a binary tree, return the preorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [1,2,3]

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

//todo move all test code for trees into seperate lib with namespace, integrate gtest

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
        root = new TreeNode(0, L1, nullptr); // root(0);
    }
    BinaryTreetest(vector<int> input_tree, tree_array_format tree_format)
    {
        // call a private method to create the tree from the list
    }
    ~BinaryTreetest()
    {
        //traverse tree in preorder way to delete all nodes
    }
};

class Solution_iterative
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> output;
        stack<TreeNode*> node_stack;
        if (root)
        { // if root is null, will simply return empty output
            node_stack.push(root);
        }
        TreeNode *working_node;
        while (!node_stack.empty())
        {
            working_node = node_stack.top();     //take from LIFO stack
            node_stack.pop();                    //
            output.push_back(working_node->val); // statement here leads to pre-order traversal
            if (working_node->right)
            {
                node_stack.push(working_node->right); // push right child to stack if it is not null
            }
            if (working_node->left)
            {
                node_stack.push(working_node->left); // push left child to stack if it is not null
            }
        }
        return output;
    }
};

class Solution_recursive
{
public:
    vector<int> preorderTraversal(TreeNode *root)
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
        tree_list.push_back(node->val);
        if (node->left != nullptr)
        {
            add_value(node->left, tree_list);
        }
        if (node->right != nullptr)
        {
            add_value(node->right, tree_list);
        }
    }
};

int main()
{
    TreeNode *Root_node;

    BinaryTreetest test1;

    Solution_recursive sol_reworking_nodesive;
    vector<int> output = sol_reworking_nodesive.preorderTraversal(test1.root);
    for (int i = 0; i < output.size(); i++)
    {
        std::cout << output.at(i) << std::endl;
    }

    Solution_iterative sol_it;
    vector<int> output_iterative = sol_it.preorderTraversal(test1.root);
    for (int i = 0; i < output.size(); i++)
    {
        std::cout << output.at(i) << std::endl;
    }
}