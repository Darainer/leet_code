//MyLinkedList
#include<iostream>

// Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class MyLinkedList {
private: 
    ListNode* head;
    //ListNode* tail;  // if we keep a tail pointer we can more efficiently perform add operations on the tail, for this exercize not added
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;  //start with an empty list
    }
    ListNode* const get_head(){
        return head;
    }
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode* current_node = head;
        int count{1};
        while(current_node != nullptr){
            if(count == index){
                return current_node->val;
            }
            else{
                current_node = current_node->next;
                count++;
            }
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* newnode = new ListNode(val);  //create a new node on the heap
        if(head != nullptr){                    //if the list was not empty, point the new node to the old head
            newnode->next = head;
        }
        head = newnode;                         //this new node is now at the head of the list
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        //would be basically a one liner with the tail pointer
        ListNode* newnode = new ListNode(val);  //create a new node on the heap
        if(head==nullptr){
            head = newnode;
        }
        else{
            ListNode* current_node{head};           //create a pointer to loop through
            while(current_node->next!=nullptr){     // stop when we current_node == tail;
                current_node = current_node->next;
            }
            current_node->next = newnode;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode* newnode = new ListNode(val);  //create a new node on the heap

        ListNode* current_node = head;
        int count{1};
        while(current_node != nullptr){
            if(count == index-1){
                newnode->next = current_node->next;
                current_node->next = newnode;
                return;
            }
            else{
                current_node = current_node->next;
                count++;
            }
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode* current_node = head;
        int count{1};
        while(current_node != nullptr){
            if(count == index-1){
                ListNode* node_to_delete = current_node->next;  // get the next pointer from the node to delete
                current_node->next = node_to_delete->next;      // link around the node_to_delete
                delete node_to_delete;                      // delete the node on the heap
                return;
            }
            else{
                current_node = current_node->next;
                count++;
            }
        }
    }
    void const printList(){
        ListNode* current_node = head;
        while(current_node != nullptr){
            std::cout << current_node->val<< " -> ";
            current_node = current_node->next;
        }
        std::cout << "NULL" << std::endl;
    }
};
 
int main(){
    MyLinkedList list;
    list.printList();
    list.addAtHead(1);
    list.printList();
    list.addAtTail(3);
    list.printList();
    list.addAtIndex(2,2);
    list.printList();
    list.deleteAtIndex(3);
    list.printList();
    list.addAtIndex(5,2);
    list.printList();
    return 0;
}

