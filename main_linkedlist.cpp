#include <iostream>

#include "LinkedList.h"

int main() {
    LinkedList<int> llist;
    

    llist.insertAtTheEnd(0); //0
    llist.insertAtTheEnd(1); //1
    llist.insertAtTheEnd(2); //2
    llist.insertAtTheEnd(3); //3
    llist.insertAtTheEnd(4); //4
    std::cout<<"Initial Size: "<<llist.getSize()<<std::endl;
    
    /*
    Node<int> *node1 = llist.getNodeAtIndex(0);
    Node<int> *node2 = llist.getNodeAtIndex(0);
    llist.swap(node1, node2);
    llist.shuffle(42);
    */
    LinkedList<int> llist_copy(llist);

    std::cout<<"Size: "<<llist_copy.getSize()<<std::endl;
    llist_copy.print();

    return 0;
}
