#include <iostream>
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int n;
    std::cout << "Enter the size of the array: " << std::endl;
    std::cin >> n;
    int* arr = new int[n];
    std::cout << "Enter " << n << " integers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Original array: " << std::endl;
    printArray(arr, n);

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    std::cout << "Array after heap construction: " << std::endl;
    printArray(arr, n);

    heapSort(arr, n);

    std::cout << "Sorted array: " << std::endl;
    printArray(arr, n);

    delete[] arr;

    return 0;
}