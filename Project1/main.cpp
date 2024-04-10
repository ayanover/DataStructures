//
// Created by rexiv on 13.03.2024.
//
#include "./include/DoublyLinkedList.h"
#include "./include/SinglyLinkedList.h"
#include "./include/DynamicArray.h"
#include "./include/TableGenerator.h"
#include <chrono>
#include <fstream>

std::vector<long long> TestDoublyLinkedListTimes(int size) {

    auto data = generateRandomVector(size);

    DoublyLinkedList<int> doublyLinkedList;
    std::vector<long long> times;

    doublyLinkedList.pushBack(1);
    for(int number : data){
        doublyLinkedList.pushBack(number);
    }

    auto start = std::chrono::high_resolution_clock::now();
    doublyLinkedList.pushBack(data[0]);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    doublyLinkedList.pushFront(data[0]);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    doublyLinkedList.popBack();
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    doublyLinkedList.popFront();
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    doublyLinkedList.insert(size/2,data[0]);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    doublyLinkedList.erase(size/2);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    doublyLinkedList.contains(data[size/2]);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    return times;
}

std::vector<long long> TestSinglyLinkedListTimes(int size) {
    auto data = generateRandomVector(size);
    SinglyLinkedList<int> singlyLinkedList;
    std::vector<long long> times;

    for(int number : data){
        singlyLinkedList.append(number);
    }
    auto start = std::chrono::high_resolution_clock::now();
    singlyLinkedList.append(data[0]);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    singlyLinkedList.prepend(data[0]);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    singlyLinkedList.remove(size-1);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    singlyLinkedList.remove(0);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    singlyLinkedList.insert(size/2,data[0]);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    singlyLinkedList.remove(size/2);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    singlyLinkedList.contains(data[size/2]);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    return times;
}

std::vector<long long> TestDynamicArrayTimes(int size) {
    auto data = generateRandomVector(size);
    DynamicArray<int> dynamicArray;
    std::vector<long long> times;

    for(int number : data){
        dynamicArray.append(number);
    }

    auto start = std::chrono::high_resolution_clock::now();
    dynamicArray.append(data[0]);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    times.push_back(duration.count());
    std::cout<<times[0]<< std::endl;

    start = std::chrono::high_resolution_clock::now();
    dynamicArray.prepend(data[0]);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());
    //std::cout<<duration.count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    dynamicArray.remove(size-1);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    dynamicArray.remove(0);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    dynamicArray.insert(size/2,data[0]);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    dynamicArray.remove(size/2);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    start = std::chrono::high_resolution_clock::now();
    dynamicArray.contains(data[size/2]);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    times.push_back(duration.count());

    return times;
}

void SaveMeasurementsToFile(std::vector<long long> data, std::string filename){
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (int i = 0; i < data.size(); i++) {
            outputFile << data[i] << "\n";
        }
        outputFile.close();
        std::cout << "Measurements saved to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

int main() {
    int ARRAY_SIZES[] = {5000, 10000, 50000, 100000};
    for(int size : ARRAY_SIZES){
        std::vector<long long> DLLTimes = TestDoublyLinkedListTimes(size);
        std::vector<long long> SLLTimes = TestSinglyLinkedListTimes(size);
        std::vector<long long> DATimes = TestDynamicArrayTimes(size);

        SaveMeasurementsToFile(DLLTimes, std::to_string(size)+"_DoublyLinkedList");
        SaveMeasurementsToFile(SLLTimes, std::to_string(size)+"_SinglyLinkedList");
        SaveMeasurementsToFile(DATimes, std::to_string(size)+"_DynamicArray");
    }
    return 0;
}
