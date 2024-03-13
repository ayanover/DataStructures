//
// Created by rexiv on 13.03.2024.
//

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void pushFront(const T &data) {
        Node *newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void pushBack(const T &data) {
        Node *newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void insert(size_t index, const T &data) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            pushFront(data);
            return;
        }
        if (index == size) {
            pushBack(data);
            return;
        }
        Node *current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        Node *newNode = new Node(data);
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
    }

    void popFront() {
        if (!head) return;
        Node *temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        size--;
    }

    void popBack() {
        if (!head) return;
        Node *temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        delete temp;
        size--;
    }

    size_t getSize() const {
        return size;
    }

    void printList() const {
        Node *current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void checkContain(const T& data ) const {

    }

private:
    struct Node {
        T data;
        Node *prev;
        Node *next;

        Node(const T &data) : data(data), prev(nullptr), next(nullptr) {}
    };

    Node *head;
    Node *tail;
    size_t size;

};

#endif /* DOUBLY_LINKED_LIST_H */

