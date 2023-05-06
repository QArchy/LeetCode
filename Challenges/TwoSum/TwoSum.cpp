#include "TwoSum.h"

std::vector<int> Solution::twoSum(std::vector<int> &nums, int target) {
    std::vector<int> vectorLessThanTarget;
    std::copy_if(
            nums.begin(),
            nums.end(),
            std::back_inserter(vectorLessThanTarget), [&target](int i) {
                return i < target;
            }
    );

    int first = 0;
    int second = 0;
    bool found = false;
    for (size_t i = 0; i < vectorLessThanTarget.size(); i++) {
        if (found)
            break;
        for (size_t j = vectorLessThanTarget.size() - 1; j > i; j--)
            if (vectorLessThanTarget[i] + vectorLessThanTarget[j] == target) {
                first = i;
                second = j;
                found = true;
                break;
            }
    }

    return std::vector<int>{first, second};
}

void Solution::main() {
    std::vector<int> vector = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> result = Solution::twoSum(vector, 5);
    for (int i : result) {
        std::cout << i << " ";
    }
}
