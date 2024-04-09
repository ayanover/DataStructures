//
// Created by rexiv on 13.03.2024.
//
#include "./include/DoublyLinkedList.h"
#include "./include/SinglyLinkedList.h"
#include "./include/DynamicArray.h"
#include "./include/TableGenerator.h"
#include <chrono>

std::vector<long> TestDoublyLinkedListTimes(int size) {
    auto data = generateRandomVector(size);
    DoublyLinkedList<int> doublyLinkedList;
    std::vector<long> times;

    for(int number : data){
        doublyLinkedList.pushBack(number);
    }

    auto start = std::chrono::high_resolution_clock::now();
    doublyLinkedList.pushBack(data[0]);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    doublyLinkedList.pushFront(data[0]);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    doublyLinkedList.popBack();
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    doublyLinkedList.popFront();
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    doublyLinkedList.insert(size/2,data[0]);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    doublyLinkedList.erase(size/2);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    doublyLinkedList.contains(data[size/2]);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    return times;
}

std::vector<long> TestSinglyLinkedListTimes(int size) {
    auto data = generateRandomVector(size);
    SinglyLinkedList<int> singlyLinkedList;
    std::vector<long> times;

    for(int number : data){
        singlyLinkedList.append(number);
    }

    auto start = std::chrono::high_resolution_clock::now();
    singlyLinkedList.append(data[0]);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    singlyLinkedList.prepend(data[0]);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    singlyLinkedList.remove(size-1);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    singlyLinkedList.remove(0);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    singlyLinkedList.insert(size/2,data[0]);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    singlyLinkedList.remove(size/2);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    singlyLinkedList.contains(data[size/2]);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    return times;
}

std::vector<long> TestDynamicArrayTimes(int size) {
    auto data = generateRandomVector(size);
    DynamicArray<int> dynamicArray;
    std::vector<long> times;

    for(int number : data){
        dynamicArray.append(number);
    }

    auto start = std::chrono::high_resolution_clock::now();
    dynamicArray.append(data[0]);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    dynamicArray.prepend(data[0]);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    dynamicArray.remove(size-1);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    dynamicArray.remove(0);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    dynamicArray.insert(size/2,data[0]);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    dynamicArray.remove(size/2);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    start = std::chrono::high_resolution_clock::now();
    dynamicArray.contains(data[size/2]);
    end = std::chrono::high_resolution_clock::now();
    duration = start - end;
    times.push_back(duration.count()*100000);

    return times;
}

int main() {
    int ARRAY_SIZES[] = {5000, 10000, 50000, 100000};
    for(int size : ARRAY_SIZES){
        std::vector<long> DLLTimes = TestDoublyLinkedListTimes(size);
        std::vector<long> SLLTimes = TestSinglyLinkedListTimes(size);
        std::vector<long> DATimes = TestDynamicArrayTimes(size);


    }



    return 0;
}
