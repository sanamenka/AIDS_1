#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void generateCostMatrix(std::vector<std::vector<int>>& cost, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cost[i][j] = 0;
            }
            else {
                cost[i][j] = rand() % 100 + 1;
            }
        }
    }
}

int calculateCost(const std::vector<int>& path, const std::vector<std::vector<int>>& cost) {
    int totalCost = 0;
    for (size_t i = 0; i < path.size() - 1; i++) {
        totalCost += cost[path[i]][path[i + 1]];
    }
    totalCost += cost[path.back()][path[0]];
    return totalCost;
}

bool nextPermutation(std::vector<int>& path, int startIdx) {
    int n = path.size();
    int i = n - 2;
    while (i >= startIdx && path[i] >= path[i + 1]) {
        i--;
    }
    if (i < startIdx) {
        return false;
    }
    int j = n - 1;
    while (path[j] <= path[i]) {
        j--;
    }
    std::swap(path[i], path[j]);
    reverse(path.begin() + i + 1, path.end());
    return true;
}

int main() {
    int n, k;
    std::cout << "Enter the number of cities (n): ";
    std::cin >> n;
    std::vector<std::vector<int>> cost(n, std::vector<int>(n));
    generateCostMatrix(cost, n);

    std::cout << "Cost matrix:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << cost[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "Enter the starting city number (k, from 0 to " << n - 1 << "): ";
    std::cin >> k;
    if (k < 0 || k >= n) {
        std::cout << "Incorrect city number!Нажмите, чтобы использовать этот вариант" << std::endl;
        return 1;
    }

    std::vector<int> P(n), Pmin(n);
    P[0] = k;
    int idx = 1;
    for (int i = 0; i < n; i++) {
        if (i != k) {
            P[idx++] = i;
        }
    }
    Pmin = P;

    int minCost = calculateCost(P, cost);

    while (nextPermutation(P, 1)) {
        int currentCost = calculateCost(P, cost);
        if (currentCost < minCost) {
            minCost = currentCost;
            Pmin = P;
        }
    }

    std::cout << "Minimum route: ";
    for (int city : Pmin) {
        std::cout << city << " -> ";
    }
    std::cout << k << std::endl;
    std::cout << "Minimum cost: " << minCost << std::endl;

    return 0;
}