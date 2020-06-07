/*
 *Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. 
 * */
#include "header.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for (int num : nums) {
            if (hash.find(num) != hash.end()) { return true; }
            hash.insert(num);
        }
        return false;
    }
};


int main(int argc, char** argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++) {
        nums.push_back(atoi(argv[i]));
    }
    cout << Solution().containsDuplicate(nums) << endl;
    return 0;
}
