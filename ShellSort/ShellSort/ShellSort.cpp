#include <iostream>

void shellSort(int* array, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int j = gap; j < size; j++) {
            for (int k = j - gap; k >= 0; k -= gap) {
                if (array[k] < array[k + gap]) {
                    break;
                }
                else {
                    int temp = array[k + gap];
                    array[k + gap] = array[k];
                    array[k] = temp;
                }
            }
        }
    }
}

bool isSorted(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int size;
    std::cout << "How many numbers you want to enter into the unsorted array: " << std::endl;
    std::cin >> size;

    int* array = new int[size];

    std::cout << "Enter the numbers for the unsorted array: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
    std::cout << "Unsorted array: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    shellSort(array, size);
    std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    if (isSorted(array, size)) 
        std::cout << "Array successfully sorted" << std::endl;
    else 
        std::cout << "Error: the array is not sorted." << std::endl;
    delete[] array;
    return 0;
}