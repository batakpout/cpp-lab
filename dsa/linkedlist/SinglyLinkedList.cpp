#include<iostream>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode * next;
        ListNode(int data) {
            this->data = data;
            this->next = nullptr;
        }
        ListNode(int data, ListNode* next) {
            this->data = data;
            this->next = next;
        }

};

class SinglyLinkedList {
    private:
        ListNode* head;
        ListNode* tail;
    public:
        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void pushFront(int val) {
            ListNode* newNode = new ListNode(val);
            if(head == nullptr) {
                head = tail = newNode;
            } else {
                newNode -> next = head;
                head = newNode;
            }
        }

        void pushBack(int val) {
            ListNode* newNode = new ListNode(val);
            if(head == nullptr) {
                head = tail = newNode;
            } else {
                /*
                    if we don't have tail then :
                    ListNode* current = head;
                    while (current->next != nullptr) {
                        current = current->next;
                    }
                    current->next = newNode;
             */
                tail -> next = newNode;
                tail = newNode;
            }
        }

        void display() {
            if(head == nullptr) {
                cout << "List is empty\n";
                return;
            } else {
                ListNode* current = head;
                cout << "List: ";
                while(current != nullptr) {
                    cout << current->data << "->";
                    current = current->next;
                }
                cout << "null\n";
            }
        }

        void insert(int val, int pos) {
            ListNode* newNode = new ListNode(val);
            if(pos == 0) {
                newNode->next=head;
                head=newNode;
            } else {
                int currentIndex=0;
                ListNode* current = head;
                // for pos = 2, this loop should run once only
                while(current != nullptr && currentIndex < pos-1) {
                    current = current->next;
                    currentIndex++;
                }
                if(current == nullptr) {
                    cout << "invalid position";
                    return;
                }
                newNode-> next = current -> next;
                current->next = newNode;

            }
        }

        int search1(int d) {
            int idx=0;
            ListNode* current = head;
            while(current != nullptr) {
                if(current-> data == d) return idx;
                current = current -> next;
                idx++;
            }
            return -1;
        }

        int search(int d) {
            return searchRecursive(head, d, 0);
        }

        int searchRecursive(ListNode* node, int d, int idx) {
            if(node == nullptr) return -1;
            if(node->data == d) {
                return idx;
            }
            return searchRecursive(node->next, d, idx++);
        }

        bool isEmpty() {
            return head == nullptr;
        }

        int size() {
            int count = 0;
            ListNode* current = head;
            while (current != nullptr) {
                count++;
                current = current->next;
            }
            return count;
        }

   /*
     * In C++, we need to manually free memory by deleting nodes.
     * This is different from Java's automatic garbage collection.
     */
        void destroy() {
            ListNode* current = head;
            while(current != nullptr) {
                ListNode* temp = current;
                current = current->next;
                delete temp;
            }
            head = tail = nullptr;
        }

        void popFront() {
            if(head == nullptr) {
                cout << "List is empty\n";
                return;
            } else {
                ListNode* temp=head;
                head = head->next;
                delete temp;
                if(head == nullptr) {
                    tail=nullptr;
                }
            }
        }

        void deleteLast() {

             if(head == nullptr) {
                cout << "List is empty\n";
                return;
            } 
            if(head->next == nullptr) {
                delete head;
                head = nullptr;
                return;
            }
            ListNode* current = head;
            while(current->next->next == nullptr) {
                current=current->next;
            }

            delete current->next;
            current->next = nullptr;

        }

        void deleteLastUsingLast() {
            if(head == nullptr) {
                cout << "List is empty\n";
                return;
            }

            if(head->next == nullptr) {
                delete head;
                head = nullptr;
                return;
            }
            ListNode* current = head;
            while(current->next != tail) {
                current=current->next;
            }
            delete tail;
            current->next=nullptr;
            tail = current;

        }

         /*
            Swapping is expensive op. what if we have songs of MBs in each node, so swaps of data will be expensive,
            moving addresses is quick as we are assigning references which is number of 4 bytes only
     */
        void reverse() {
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
            head = prev;
        }

        ListNode* recursiveReverseHelper(ListNode* head) {
            if(head == nullptr || head->next == nullptr) return head;
            ListNode* newHead = recursiveReverseHelper(head->next);
            head->next->next = head;
            head->next=nullptr;
            return newHead;
        }

        void recursiveReverse(ListNode* head) {
            if(head == nullptr || head->next == nullptr) return;
            tail=head;
            head = recursiveReverseHelper(head);
        }

        void kReverse(int k) {
            head = kReverseRecursive(head, k);
        }

        ListNode* kReverseRecursive(ListNode* head, int k) {
            if (head == nullptr || k <= 1) return head;
            ListNode* current=head;
            ListNode* temp;
            ListNode* prev = nullptr;
            int cnt=1;

            while (current != nullptr && cnt <= k) {
                temp = current->next;
                current->next = prev;
                prev=current;
                current=temp;
                cnt++;
            }

            if(temp != nullptr) {
                head->next = kReverseRecursive(temp, k);
            }
            return prev;

        }





};

int main() {
    
    return 0;
}
