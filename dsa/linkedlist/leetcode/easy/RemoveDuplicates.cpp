/**
  LC: 83: E:  Remove Duplicates from Sorted List
  Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
  Input: head = [1,1,2]
  Output: [1,2]

 Input: head = [1,1,2,3,3]
 Output: [1,2,3]
  The number of nodes in the list is in the range [0, 300].
  -100 <= Node.val <= 100
 The list is guaranteed to be sorted in ascending order.
 */

#include "../../linked_list_header.h" 

// Approach 1: Simple O(N) method
 ListNode* deleteDuplicates(ListNode* head) { 
    /**
     head (the pointer variable) is passed by value - so head itself won't change in the caller
    But head points to the same memory location as the original list
    When you modify curr->next, you're changing the actual linked list nodes in memory
     */
    ListNode* curr = head;
    while(curr != NULL && curr->next != NULL) {
        if(curr->data == curr->next->data) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
    return head;
 }

 // Approach 2:  O(N) 
 ListNode* deleteDuplicates2(ListNode* head) { 
    if (!head) return nullptr;

    ListNode* prev = head;
    ListNode* temp = head;
    while(temp != nullptr) {
        if(temp->data == prev->data) {
            temp = temp->next;
            continue;
        }
        prev->next = temp;
        prev = temp;
        temp = temp->next;
    }
    prev->next=nullptr;
    return head;
 }

