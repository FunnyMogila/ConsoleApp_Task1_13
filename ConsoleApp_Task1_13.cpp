#include <iostream>
#include <vector>

bool isAlternating(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        return false;
    }

    bool isPositive = numbers[0] > 0;
    for (size_t i = 1; i < numbers.size(); ++i) {
        if ((numbers[i] > 0) == isPositive) {
            return false;
        }
        isPositive = !isPositive;
    }
    return true;
}

int main() {
    int rows, cols;

    std::cout << "Enter number of rows: ";
    std::cin >> rows;

    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        std::cout << "Enter numbers for row " << i + 1 << ": ";
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<bool> results;

    for (const auto& row : matrix) {
        results.push_back(isAlternating(row));
    }

    for (size_t i = 0; i < results.size(); ++i) {
        std::cout << "Row " << i + 1 << ": " << (results[i] ? "true" : "false") << std::endl;
    }

    return 0;
}