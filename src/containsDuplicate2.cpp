/*
 *Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. 
 * */
#include "header.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            auto it = hash.find(nums[i]);
            if (it != hash.end() && (i - it->second) <= k) { return true; }
            hash[nums[i]] = i;
        }
        return false;
    }
};

int main(int argc, char** argv) {
    vector<int> nums;
    for (int i = 1; i < argc - 1; i++) {
        nums.push_back(atoi(argv[i]));
    }
    cout << Solution().containsNearbyDuplicate(nums, atoi(argv[argc - 1])) << endl;
    return 0;
}
