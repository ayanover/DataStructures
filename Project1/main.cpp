//
// Created by rexiv on 13.03.2024.
//
#include "./include/DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> LinkedList;
    LinkedList.pushBack(1);
    LinkedList.pushBack(3);
    LinkedList.pushBack(4);


    std::cout << "List after insertion: ";
    LinkedList.printList();

    return 0;
}
