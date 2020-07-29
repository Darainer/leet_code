#include<iostream>

// Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        while(head != nullptr){          
            ListNode* next_node = head->next;       // Move the head pointer along the list until the end is reached 
            head->next = previous;                  // link the next node to the previous one
            previous = head;                        // Move both the previous and head pointers along the list until the end is reached
            head = next_node;              
        }
        return previous;
    }
};
 
int main(){
    ListNode* fifth = new ListNode(5);
    ListNode* fourth = new ListNode(4,fifth);
    ListNode* third = new ListNode(3, fourth);
    ListNode* second = new ListNode(2,third);
    ListNode* head = new ListNode(1,second);
    Solution mysolution;
    ListNode* newhead = mysolution.reverseList(head);
    while(newhead!= nullptr){
        std::cout << newhead->val<< " -> ";
        newhead = newhead->next;
    }
    std::cout << "NULL" << std::endl;
    return 0;
}