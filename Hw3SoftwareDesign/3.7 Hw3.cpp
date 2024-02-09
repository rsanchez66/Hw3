#include <iostream>
#include <vector>
#include <unordered_map>


int findMode(const std::vector<int>& nums) {
    std::unordered_map<int, int> countMap; // occurrences of each number
   
    // occurrences of each number in the array
    for (int num : nums) {
        countMap[num]++;
    }
   
    // the mode (number with the highest frequency)
    int mode = 0;
    int maxCount = 0;
    for (const auto& pair : countMap) {
        if (pair.second > maxCount) {
            mode = pair.first;
            maxCount = pair.second;
        }
    }
   
    return mode;
}


int main() {
    std::vector<int> nums = {1, 3, 5, 3, 2, 3, 1, 4, 3, 2, 1};
   
    int mode = findMode(nums);
   
    std::cout << "Mode: " << mode << std::endl;
   
    return 0;
}