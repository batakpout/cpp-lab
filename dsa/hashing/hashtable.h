
/** 
======================  Hash Table Layout  ======================


   Node** table
   ┌──────────────────────────┐
   │ 0 : Node* (NULL)         │
   │ 1 : Node*                │──► [K,V] -> [K,V] -> NULL
   │ 2 : Node*                │──► [K,V] -> NULL
   │ 3 : Node* (NULL)         │
   │ 4 : Node*                │──► [K,V] -> NULL
   │ 5 : Garbage / empty ...  │
   │ ...                      │
   │ 9 : (up to TS-1)         │
   └──────────────────────────┘
         ↑
         Table  (array of Node* pointers)
         TS = table size   (e.g. 10)
         CS = current count of stored entries (e.g. 2)

   ┌──────────────┐
   │   Node<T>    │
   ├──────────────┤
   │ string key   │
   │ T value      │
   │ Node* next   │  -> forms linked list in each bucket
   └──────────────┘

   Hash Function
   -------------
       f(key)  → int
       (maps string key to an index 0 … TS-1)

   Main
   ----
       Hashtable<T> ht;
       Node<T> *head;    // per bucket

   Notes
   -----
   • table is dynamically allocated: new Node<T>*[TS]
   • each bucket holds a linked list of Node<T> entries
   • CS = number of inserted key–value pairs
   • TS = total slots in the table (capacity)

    - If table size is 5 and we have 200 entries then that means we have 40 nodes in each, so we load factor of 0.7 to expand table
================================================================

*/
#include<iostream>
using namespace std;
template<typename T>
class Node {
 public:
    string key;
    T data;
    Node* next;
    Node(string key, T data) {
        this->key = key;
        this->data = data;
        next = nullptr;
    }
    ~Node() { // when current node is deleted in rehashing as delete temp; all nodes in next of that node has to be deleted
        if(next != NULL) {
            delete next; //this will create chain of next which will then delete next node
        }
    }
};

template<typename T>
class HashTable {
    Node<T>** table;
    int cs;
    int ts;
     /*
            so idx depends upon size of table so idx will change
            O(N) for insert during rehash but amortized O(1)
        */
    void rehash() {
            cout <<"\n==rehashing==\n";
            Node<T>** oldTable = table;
            int oldTs = ts;
            ts = ts*2+1;
            cs=0;
            table = new Node<T>*[ts];
            for(int i=0;i<ts;i++) {
                table[i] =NULL;
            }


            for(int i=0;i<oldTs;i++) {
                Node<T>*temp = oldTable[i];
                while(temp != NULL) {
                    string key = temp->key;
                    T data = temp->data;
                    insert(key, data);
                    temp=temp->next;
                }
               if(oldTable[i] != NULL)  {
                delete oldTable[i];
               }
            }

            if(oldTable != NULL) {
                delete [] oldTable;
            }

        }
    public: 
        HashTable(int default_size = 7) {
            cs=0;
            ts=default_size;
            table = new Node<T>*[ts];
            for(int i=0;i<ts;i++) {
                table[i] = NULL;
            }
        }

        int hashFn(string key) {
            int idx = 0;
            int pow = 1;
            for(char ch: key) {
                idx = (idx + ch*pow)%ts;
                pow = (pow*29)%ts; //%ts not really needed here
            }
            return idx;
        }

        void insert(string key, T data) {
            Node<T>* n = new Node<T>(key, data);
            int idx = hashFn(key);
            //ensure this alwasy remains O(1)
            n->next = table[idx];
            table[idx]=n;
            cs++;
            float load_factor = cs/float(ts);
            if(load_factor > 111) { //keep it 0.7, changed for test purposes
                rehash();
            }

        }

        void print() {
            for(int i=0;i<ts;i++) {
                cout << "Bucket: " << i << " ";
                Node<T>* temp = table[i];
                while(temp != NULL) {
                    cout << temp->key << "->" << temp->data << " , ";
                    temp=  temp->next;
                }
                cout << endl;
            }
        }

        T* search(string key) {
            int idx = hashFn(key);
            Node<T>* temp = table[idx];
            while(temp != NULL) {
                if(temp->key == key) {
                    return &temp->data;
                }
                temp=temp->next;
            }
            return nullptr;
        }

        //we have to comment out ~Node destructor before this
        void erase(string key) {
            int idx = hashFn(key);
            Node<T> * temp = table[idx];
            Node<T> * prev=NULL;

            while(temp != NULL) {
                if(temp->key == key) {
                   if(prev==NULL) {
                     table[idx] = temp->next;
                   } else {
                        prev->next = temp->next;
                   }
                   temp->next = NULL; //so ~Node destructor won't kick in
                    delete temp;
                    return;
                }
                prev=temp;
                temp=temp->next;

            }          
        }

        /**
         why T& works here:
         Memory location 0x1000 contains: [some integer value; temp->data]
        valueFound = 0x1000              (pointer to that location)
        *valueFound = [the integer]      (the actual value at 0x1000)
        return *valueFound               (reference to location 0x1000)

        h["banana"] = 310 now writes 310 directly to location 0x1000
         */
        T& operator[](string key) {
            T* valueFound =  search(key);
            if(valueFound == NULL) {
                T obj;
                insert(key, obj);
                valueFound = search(key);
            }
            return *valueFound;
        }
        

};

