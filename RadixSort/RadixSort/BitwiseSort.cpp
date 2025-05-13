#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

void bitwise_sort(std::vector<int>& arr, int l, int r, int k) {
    if (l >= r || k < 0) {
        return;
    }

    int i = l;
    int j = r;

    while (i <= j) {

        while (i <= j && !(arr[i] & (1 << k))) {
            i++;
        }

        while (i <= j && (arr[j] & (1 << k))) {
            j--;
        }

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    bitwise_sort(arr, l, j, k - 1);
    bitwise_sort(arr, i, r, k - 1);
}

void bitwise_sort(std::vector<int>& arr) {
    if (arr.empty()) return;
    int max_num = *std::max_element(arr.begin(), arr.end(),
        [](int a, int b) { return std::abs(a) < std::abs(b); });
    int k = 0;
    while (max_num != 0) {
        max_num >>= 1;
        k++;
    }
    k--;

    bitwise_sort(arr, 0, arr.size() - 1, k);
}

int main() {
    std::vector<int> arr = { 12, 5, 8, 8, 17, 3, 10 };
    std::cout << "Original array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    bitwise_sort(arr);

    std::cout << "Sorted array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}