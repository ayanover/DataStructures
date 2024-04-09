//
// Created by rexiv on 13.03.2024.
//

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class DoublyLinkedList {
public:
    // Default constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Copy constructor
    DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr), size(0) {
        Node* current = other.head;
        while (current) {
            pushBack(current->data);
            current = current->next;
        }
    }

    // Copy assignment operator
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current) {
                pushBack(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // Destructor
    ~DoublyLinkedList() {
        clear();
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

    void erase(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            popFront();
            return;
        }
        if (index == size - 1) {
            popBack();
            return;
        }
        Node *current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }

    // Utility methods
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

    bool contains(const T& data) const {
        Node *current = head;
        while (current) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void clear() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }
private:
    // Node structure
    struct Node {
        T data;
        Node *prev;
        Node *next;

        Node(const T &data) : data(data), prev(nullptr), next(nullptr) {}
    };

    // Private member variables
    Node *head;
    Node *tail;
    size_t size;
};

#endif /* DOUBLY_LINKED_LIST_H */


