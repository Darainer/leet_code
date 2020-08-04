//binary tree depth

#include <vector>
#include <queue>
#include <stack>
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

class Solution
{
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> node_queue;
        if (root)
        { // if root is null, will simply return empty output
            node_queue.push(root);
        }
        TreeNode *working_node;
        int levels{0}, max_depth{0};
        while (!node_queue.empty())
        {
            int level_size = node_queue.size()-1;
            for( int i = 0; i <= level_size; i++ ){     //process nodes on current level from LIFO queue
                working_node = node_queue.front();     
                node_queue.pop();                    
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
            if (levels>max_depth){
                max_depth = levels;}
        }
        return max_depth;
    }

    int maxDepth_recursive(TreeNode* root) {
        if(root== nullptr){return 0;}
        return getDepth(root,1);
    }
private:
    int getDepth(TreeNode* current , int depth){
        int left{depth}, right{depth};
        if(current->left != nullptr) { 
        left = getDepth(current->left, depth+1);
        }
         if(current->right != nullptr) { 
        right = getDepth(current->right, depth+1);
        }
        return std::max(left,right);
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

    Solution sol;
    int depth = sol.maxDepth(test1.root);
    int depth_rec = sol.maxDepth_recursive(test1.root);
    std::cout << "max tree depth = " << depth << endl; 
    std::cout << "max tree depth = " << depth_rec << endl; 
}