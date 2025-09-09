

  /*

LC 234 Easy Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome or false otherwise

Input: head = [1,2,2,1]
Output: true


    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9


do it in O(n) time and O(1) space?
**/



 
#include "../../linked_list_header.h"

ListNode* findMidPoint(ListNode* head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next;
        while(fastPtr != NULL && fastPtr->next != NULL) {
            slowPtr=slowPtr->next;
            fastPtr=fastPtr->next->next;
        }
        return slowPtr;
}

ListNode* reverse(ListNode* head) {
    ListNode* current = head;
    ListNode* prev=nullptr;
    ListNode* temp;
    //tail = current; ?
    while(current != nullptr) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
}


/*
Complexity Analysis of the function:

Operation        Time     Space
--------------------------------
Find midpoint    O(N)     O(1)
Reverse half     O(N/2)   O(1)
Compare halves   O(N/2)   O(1)
--------------------------------
Total            O(N)     O(1)
*/
bool isPalindrome(ListNode* head) {
    if(head==NULL || head->next == NULL) {
        return true;
    }

    ListNode* mid = findMidPoint(head);
    ListNode* secondHalfHead = reverse(mid->next);      
    ListNode* firstHalfHead = head;
    bool palindrome = true;
    while(secondHalfHead != NULL) {
        if(firstHalfHead->data != secondHalfHead->data) {
            palindrome=false;
            break;
        }
        firstHalfHead = firstHalfHead->next;
        secondHalfHead = secondHalfHead->next;
    }
    //mid->next = reverse(secondHalfHead) to undo second half if needed
    return palindrome;
}

bool bitFaster(ListNode* head) {
    if (!head || !head->next) return true;

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* prev = nullptr;
    ListNode* curr = slow;
    while (curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }


    ListNode* left = head;
    ListNode* right = prev;
    while (right) { 
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->next;
    }

    return true;
}

//fastest but O(N) space
bool isPalindrome(ListNode* head) {
         vector<int> vals;

    while (head) {
        vals.push_back(head->data);
        head = head->next;
    }

    int left = 0, right = vals.size() - 1;
    while (left < right) {
        if (vals[left] != vals[right]) return false;
        left++;
        right--;
    }

    return true;
}

int main() {
    SinglyLinkedList list;
    
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(2);
    list.pushBack(1);

    list.display();

    bool res = isPalindrome(list.getHead());
    cout << ((res == 1) ? "Palindrome" : "Not Palindrome");
    cout << endl;

}