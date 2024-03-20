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
    std::vector<std::vector<int>> matrix = {
        {1, -2, 3, -4, 5},
        {-1, 2, -3, 4, -5},
        {-1, -2, -3, -4},
        {1, 2, 3, 4, 5},
        {-1, 2, -3, 4, -5}
    };

    std::vector<bool> results;

    for (const auto& row : matrix) {
        results.push_back(isAlternating(row));
    }

    for (size_t i = 0; i < results.size(); ++i) {
        std::cout << "Row " << i + 1 << ": " << (results[i] ? "true" : "false") << std::endl;
    }

    results.clear();

    return 0;
}