#include "hashtable.h"

int main() {

    HashTable<int> h;
	h.insert("Mango",100);
	h.insert("Apple",120);
	h.insert("Banana",140);
	h.insert("Orange",200);
    h.insert("Kiwi",210);
	h.insert("Papapya",220);
	h.insert("Litchi",30);
    h.print();
    return 0;
}