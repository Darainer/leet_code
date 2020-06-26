// binary_tree_levelorder_Traversal
// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

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
        //     3
        //    / \
        //   9  20
        //     /  \
        //    15   7
        TreeNode *L1;
        TreeNode *L2;
        TreeNode *L3;
        TreeNode *L4;
        L4 = new TreeNode(7,nullptr,nullptr);
        L3 = new TreeNode(15,nullptr,nullptr);
        L2 = new TreeNode(20, L3, L4);
        L1 = new TreeNode(9);
        root = new TreeNode(3, L1, L2); // root(0);
    }
    BinaryTreetest(vector<int> input_tree)
    {
        // call a private method to create the tree from the list
    }
    ~BinaryTreetest()
    {
        //traverse tree in [postorder way to delete all nodes
    }
};

class Solution_iterative
{
public:
    vector<vector<int>> levelorder_Traversal(TreeNode *root){
        vector<vector<int>> output;
        queue<TreeNode*> node_queue;
        if (root)
        { // if root is null, will simply return empty output
            node_queue.push(root);
        }
        TreeNode *working_node;
        int levels{0};
        while (!node_queue.empty())
        {
            int level_size = node_queue.size()-1;
            output.push_back({});
            for( int i = 0; i <= level_size; i++ ){     //process nodes on current level from LIFO queue
                working_node = node_queue.front();     
                node_queue.pop();                    
                output.at(levels).push_back(working_node->val);
                if (working_node->left)
                {
                    node_queue.push(working_node->left); // push left child to queue if it is not null
                }
                if (working_node->right)
                {
                    node_queue.push(working_node->right); // push right child to queue if it is not null
                }
            }
            levels++;
        }
        return output;
    }
};

class Solution_recursive
{
public:
    vector<vector<int>> levelorder_Traversal(TreeNode *root)
    {
        vector<vector<int>> tree_list{};
        if (root != nullptr)
        {
            add_value(root, tree_list,0);
        }
        return tree_list;
    }

private:
    void add_value(TreeNode *node, vector<vector<int>> &tree_list,int depth)
    {
        if( tree_list.size() < depth+1 ){
            tree_list.push_back({});
        }
        tree_list.at(depth).push_back(node->val);
        if (node->left != nullptr){
            add_value(node->left, tree_list, depth+1);
        }
        
        if (node->right != nullptr){
            add_value(node->right,tree_list, depth+1);
        }
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
    TreeNode *Root_node;

    BinaryTreetest test1;

    Solution_recursive sol_rec;
    vector<vector<int>> output = sol_rec.levelorder_Traversal(test1.root);
    print_test(output);

    Solution_iterative sol_it;
    vector<vector<int>> output_iterative = sol_it.levelorder_Traversal(test1.root);
    print_test(output_iterative);
}