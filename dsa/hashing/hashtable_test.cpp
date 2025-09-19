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
	h.insert("Melon",60);
	h.insert("peach",230);
    h.print();

	// cout<<"Search a fruit price:"; 
	// string fruit;cin>>fruit;
	// int* res = h.search(fruit);
	// if(res != NULL) {
	// 	cout << "Fruit found: " << *res << endl;
	// } else {
	// 	cout << "Fruit not found\n";
	// }


	// h.erase("Papapya");
	// cout << endl;
	// cout << "hastable after erasure:\n";
	// h.print();

	int * res1 = h.search("Litchi");
	if(res1 != NULL) {
		cout << "Fruit found: " << *res1 << endl;
	} else {
		cout << "Fruit not found\n";
	}

	h["banana"] = 310;
	h["Apple"] += 598;
	h.print();

    return 0;
}