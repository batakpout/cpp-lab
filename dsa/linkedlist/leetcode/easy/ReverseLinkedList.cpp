
/**
 LC: E: 206. Reverse Linked List

 Given the head of a singly linked list, reverse the list, and return the reversed list.
 */
#include "../../linked_list_header.h"

ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* temp = nullptr;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            temp = curr->next;   
            curr->next = prev;   
            prev = curr;         
            curr = temp;      
        }
        head = prev;
        return head;
    }