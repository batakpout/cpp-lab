#include<iostream>
#include<unordered_set>
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

        ListNode* getHead() {
            return head;
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
            return searchRecursive(node->next, d, idx +1); // don't use idx++, it passes current idx and then increments
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

        SinglyLinkedList mergeSortedNodes(SinglyLinkedList list1, SinglyLinkedList list2) {
            ListNode* head1 = list1.head;
            ListNode* head2 = list2.head;
            SinglyLinkedList newList;

            while(head1 != nullptr && head2 != nullptr) {
                if(head1->data < head2->data) {
                    newList.pushBack(head1-> data);
                    head1 = head1->next;
                } else {
                    newList.pushBack(head2->data);
                    head2 = head2->next;
                }
            }

            while(head1 != nullptr) {
                newList.pushBack(head1->data);
                head1 = head1->next;
            }

            while(head2 != nullptr) {
                newList.pushBack(head2->data);
                head2 = head2->next;
            }

            return newList;
        }

        ListNode* mergeSortedNodesRecursive(ListNode* head1, ListNode* head2) {
            if(head1 == NULL) return head2;
            if(head2 == nullptr) return head1;

            ListNode* res;

            if(head1->data < head2-> data) {
                res = head1;
                res->next = mergeSortedNodesRecursive(head1->next, head2);
            } else {
                res = head2;
                res->next = mergeSortedNodesRecursive(head1, head2-> next);
            }
            return res;
        }

        // Example: For 1→2→3→4→5→6→7 and K=3 → Output: 5
        int kthLastElementNaive(int k) {

            int n=0;
            ListNode* curr = head;
            while(curr!=NULL) {
                curr = curr-> next;
                n++;
            }
            curr = head;
            for(int i=0;i<n-k;i++) {
                curr = curr->next;
            }
            return curr->data;
        }

        int kthLastElementOptimized(int k) {
            ListNode* slowPtr = head;
            ListNode* fastPtr = head;
            int i=0;
             //keep k step gap between the slow and fast pointe
            while(i<k) {
                fastPtr=fastPtr->next;
                i++;
            }
            //now move fast and slow pointer, once fast reaches null, slower will
        // be k steps away from fast pointer
            while(fastPtr != NULL) {
                slowPtr = slowPtr -> next;
                fastPtr = fastPtr->next;
            }

            return slowPtr->data;
            
        }

        /*
            alternative merge
            1->2->3->4
            5->6->7->8
            output: 1->5->2->6->3->7->4->8
        */
        SinglyLinkedList alternativeMerge(SinglyLinkedList list1, SinglyLinkedList list2) {
            ListNode* head1 = list1.head;
            ListNode* head2 = list2.head;
            SinglyLinkedList newList;

            while(head1 != nullptr && head2 != nullptr) {
                    newList.pushBack(head1-> data);
                    head1 = head1->next;
                    newList.pushBack(head2->data);
                    head2 = head2->next;
            }

            while(head1 != nullptr) {
                newList.pushBack(head1->data);
                head1 = head1->next;
            }

            while(head2 != nullptr) {
                newList.pushBack(head2->data);
                head2 = head2->next;
            }

            return newList;
        }

        void bubbleSort() {
            ListNode* curr = head;
            int n=0;
            while(curr != NULL) {
                curr=curr->next;
                n++;
            }

            int temp;
            bool swapped;
            for(int i=0;i<n-1;i++) {
                curr = head;
                swapped = false;
                for(int j=0;j<n-i-1;j++) {
                    if(curr->data > curr->next->data) {
                        swapped = true;
                        temp = curr->data;
                        curr->data = curr->next->data;
                        curr->next->data = temp;
                    }
                    if(!swapped) {
                        break;
                    }
                }
            }
        }

        //using runner technique
        ListNode* findMidPoint(ListNode* curr) {
            ListNode* slowPtr = curr;
            ListNode* fastPtr = curr->next;
            while(fastPtr != NULL && fastPtr->next != NULL) {
                slowPtr=slowPtr->next;
                fastPtr=fastPtr->next->next;
            }
            return slowPtr;
        }

        ListNode* mergeSort(ListNode * head) {
            if(head == NULL || head->next == NULL) {
                return head;
            }
            ListNode* mid = findMidPoint(head);
            ListNode* a = head;
            ListNode* b = mid->next;
            mid->next=NULL;
            a = mergeSort(a);
            b = mergeSort(b);
            return mergeSortedNodesRecursive(a, b);
        }

        //TC: O(N), SC: O(N)
        bool detectCycle1(ListNode* head) {
            unordered_set<ListNode*> nodeSet;
            ListNode* curr = head;
            while(curr != NULL) {
                if(nodeSet.find(curr) != nodeSet.end()) {
                    return true;
                }
                nodeSet.insert(curr);
                curr = curr->next;
            }
            return false;
        }

        //TC: O(N), SC: O(1)
        bool detectCycle2(ListNode* head) {
            ListNode* slowPtr = head;
            ListNode* fastPtr = head;
            while(slowPtr != NULL && fastPtr != NULL && fastPtr->next != NULL) {
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next->next;
                if(slowPtr == fastPtr) {
                    return true;
                }
            }
            return false;
        }

};

        void print(ListNode* head) {
                ListNode* curr = head;
                while (curr != nullptr) {
                    cout << curr->data << "-->";
                    curr = curr->next;
                }
                cout << "NULL" << endl;
        }

int main() {

    SinglyLinkedList list;

    cout << "Initial list:" << endl;
    list.display();
    cout << "Is empty: " << (list.isEmpty() ? "true" : "false") << endl;

    // Add elements to the front
    list.pushFront(40);
    cout << "\nAfter adding 40:" << endl;
    list.display();

    list.pushFront(20);
    cout << "\nAfter adding 20:" << endl;
    list.display();

    list.pushFront(10);
    cout << "\nAfter adding 10:" << endl;
    list.display();

    cout << "\nList size: " << list.size() << endl;
    cout << "Is empty: " << (list.isEmpty() ? "true" : "false") << endl;

    cout << "\nAfter appending 50, 60: " << endl;
    list.pushBack(50);
    list.pushBack(60);
    cout << "\nAfter inserting 30 at pos 2: " << endl;
    list.insert(30, 2);
    list.pushBack(70);
    list.pushBack(80);
    list.display();

    int searchIndex = list.search(40);
    cout << "40 is found at index: " << searchIndex << endl;
    
   // list.destroy();
    //cout << "Popping front of the list:" << endl;
    //list.popFront();

    cout << "k(3)-reverse:" << endl;
    list.kReverse(3);
    list.display();
    cout << endl;

    SinglyLinkedList list1;
    list1.pushBack(1);
    list1.pushBack(5);
    list1.pushBack(7);
    list1.pushBack(10);

    SinglyLinkedList list2;
    list2.pushBack(2);
    list2.pushBack(3);
    list2.pushBack(6);
    list1.display();
    list2.display();

    cout << "Merging two lists output: " << endl;
    ListNode* merged = list.mergeSortedNodesRecursive(list1.getHead(), list2.getHead());
    print(merged);
    cout << endl;

    cout << "Merge sort:";
    SinglyLinkedList mergeSortList;
    mergeSortList.pushBack(6);
    mergeSortList.pushBack(1);
    mergeSortList.pushBack(5);
    mergeSortList.pushBack(2);
    mergeSortList.pushBack(4);
    mergeSortList.pushBack(3);
    ListNode* newHead = mergeSortList.mergeSort(mergeSortList.getHead());
    print(newHead);
    cout << endl;

    cout << "\n=== Testing Cycle Detection ===" << endl;

    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(1);
    ListNode* intersection = new ListNode(8);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = intersection;
    intersection->next = node4;
    node4->next = node5;
    node5->next = intersection;  // This creates the cycle - points back to intersection

    SinglyLinkedList cycleList1;
    bool hasCycle1 = cycleList1.detectCycle1(node1);
    cout << "detectCycle1 (hash set method): " << (hasCycle1 ? "Cycle detected" : "No cycle") << endl;

    // (Floyd's algorithm - tortoise and hare)
    SinglyLinkedList cycleList2;
    bool hasCycle2 = cycleList2.detectCycle2(node1);
    cout << "detectCycle2 (Floyd's algorithm): " << (hasCycle2 ? "Cycle detected" : "No cycle") << endl;
    cout << endl;

    // Test with a list without cycle
    ListNode* noCycleHead = new ListNode(1);
    noCycleHead->next = new ListNode(2);
    noCycleHead->next->next = new ListNode(3);
    noCycleHead->next->next->next = new ListNode(4);

    bool noCycle1 = cycleList1.detectCycle1(noCycleHead);
    bool noCycle2 = cycleList2.detectCycle2(noCycleHead);
    cout << "No cycle test - detectCycle1: " << (noCycle1 ? "Cycle detected" : "No cycle") << endl;
    cout << "No cycle test - detectCycle2: " << (noCycle2 ? "Cycle detected" : "No cycle") << endl;
    cout << endl;
    return 0;
}