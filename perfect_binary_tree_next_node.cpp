// Populating Next Right Pointers in Each Node

// Solution
// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Follow up:

// You may only use constant extra space.
// Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

// The number of nodes in the given tree is less than 4096.
// -1000 <= node.val <= 1000

// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]
// Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//notes. Usable property of the perfect tree is the form is known 
// each level has 2^level items, the last one points to NULL.
// 

class BinaryTreetest
{
public:
    TreeNode *root;
    BinaryTreetest()
    {
        //      3
        //    /   \
        //   9     20
        //  / \   /  \
        // 5   4 15   7

        
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

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> node_queue;
        if (root){ // if root is null, will simply return empty output
            node_queue.push(root);
        }
        Node *working_node;
        int levels{0};
        while (!node_queue.empty())
        {
            int level_size = node_queue.size()-1;
            for( int i = 0; i <= level_size; i++ ){     //process nodes on current level from LIFO queue
                working_node = node_queue.front();     
                node_queue.pop();
                if(i==level_size){
                    working_node->next = NULL;
                }                   
                else{
                    working_node->next = node_queue.front();
                }
                if (working_node->left )                // stops at the bottom of the tree
                {
                    node_queue.push(working_node->left); // push left child to queue if it is not null
                    node_queue.push(working_node->right); // push right child to queue if it is not null
                }
            }
            levels++;
        }
        return root;
    }
    Node* connect_imperfect_tree(Node* root) {
        queue<Node*> node_queue;
        if (root){ // if root is null, will simply return empty output
            node_queue.push(root);
        }
        Node *working_node;
        int levels{0};
        while (!node_queue.empty())
        {
            int level_size = node_queue.size()-1;
            for( int i = 0; i <= level_size; i++ ){     //process nodes on current level from LIFO queue
                working_node = node_queue.front();     
                node_queue.pop();
                if(i==level_size){
                    working_node->next = NULL;
                }                   
                else{
                    working_node->next = node_queue.front();
                }
                if (working_node->left )                // stops at the bottom of the tree
                {
                    node_queue.push(working_node->left); // push left child to queue if it is not null
                }
                if(working_node->right){
                    node_queue.push(working_node->right); // push right child to queue if it is not null
                }
            }
            levels++;
        }
        return root;
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
    
    Node *Root_node;
    Solution my_solution;
    my_solution.connect(Root_node);
    std::cout << Root_node->next << '/n';
    

}