//Linked List Cycle

// Given a linked list, determine if it has a cycle in it.

// if you want a position, maybe use a map for lookup of the position?

#include<iostream>

// Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

void const printList(ListNode* head){
    ListNode* current_node = head;
    while(current_node != nullptr){
        std::cout << current_node->val<< " -> ";
        current_node = current_node->next;
    }
    std::cout << "NULL" << std::endl;
}

class Solution {
public:
bool hasCycle(ListNode* head){
    if( head == nullptr || head->next == nullptr){return -1;}
    ListNode* slow_p {head};
    ListNode* fast_p {head->next};

    while(slow_p != fast_p){
        if(slow_p == nullptr || fast_p == nullptr){         // if we can get to the end of the list, then its 
            return 0;
        }
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
    }
    return 1;
}

};

int main(){
    ListNode* fifth = new ListNode(5);
    ListNode* fourth = new ListNode(4,fifth);
    ListNode* third = new ListNode(2, fourth);
    ListNode* second = new ListNode(2,third);
    ListNode* head = new ListNode(1,second);
    Solution mysolution;
    int hasCycle_false = mysolution.hasCycle(head);
    std::cout << "hascycle = "<< hasCycle_false<< std::endl;
    printList(head);

    fourth->next = second;
    int hasCycle_true = mysolution.hasCycle(head);
    std::cout << "hascycle = "<< hasCycle_true<< std::endl;

    return 0;
}
