
/**
 LC: E: 160. Intersection of Two Linked Lists
 Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the
 two linked lists have no intersection at all, return null.

 Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3

 */


#include "../../linked_list_header.h"
#include<unordered_set>

// Approach 1: Using a HashSet - O(N+M) time, O(N) space
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    unordered_set<ListNode*> set;
    ListNode* curr = headA;
    while(curr != nullptr) {
        set.insert(curr);
        curr = curr->next;
    }
    curr = headB;
    while(curr) {
        if(set.find(curr) != set.end()) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}
/**
 In C++, when you pass headA to the function len(ListNode* head), you're passing by value. 
 The original headA pointer remains unaffected
 */
int len(ListNode* head) {
    int c=0;
    while(head != nullptr) {
        c++;
        head=head->next;
    }
    return c;
}

// Approach 2: Two-pointer technique - O(N+M) time, O(1) space
ListNode* getIntersectionNode2(ListNode* headA, ListNode* headB) {
    int l1 = len(headA);
    int l2 = len(headB);

    while(l1 > l2) {
        headA = headA->next;
        l1++;
    }
    
    while(l2 > l1) {
        headB = headB->next;
        l2++;
    }

    while(headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;


}
