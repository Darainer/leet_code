#include<iostream>

// Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


// edge cases: need to update the head pointer if it is deleted... if(current_node == head ){ head = current_node->next;}
// not done here, but we could want to free memory on heap if desired (could be that we only remove from this particular list)


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head== nullptr){return head;}
        ListNode* current_node = head;               
        ListNode* previous_node = nullptr;

        while(current_node != nullptr){          
            if(current_node->val == val){
                // remove node
                //case 1: node is head
                if(current_node == head){
                    head = current_node->next;
                }
                // case 2: any other node
                else{
                    previous_node->next = current_node->next;
                }
            }  
            else{  
                previous_node = current_node;  //if we didnt remove current_node, then we move the previous node pointer
            }

            current_node = current_node->next;            
    }
    return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;               // will be at the tail
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
    ListNode* third = new ListNode(2, fourth);
    ListNode* second = new ListNode(2,third);
    ListNode* head = new ListNode(1,second);
    Solution mysolution;
    ListNode* newhead = mysolution.removeElements(head,5);
    while(newhead!= nullptr){
        std::cout << newhead->val<< " -> ";
        newhead = newhead->next;
    }
    std::cout << "NULL" << std::endl;
    return 0;
}