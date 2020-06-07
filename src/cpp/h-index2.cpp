/*
 *Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm? 
 * */
#include "header.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int l = 0, r = citations.size() - 1;
        while (l < r) {
            int val = (l + r) / 2;
            if (citations.size() - val > citations[val]) {
                l = val + 1;
            } else if (citations.size() - val < citations[val]) {
                r = val;
            } else {
                return citations.size() - val;
            }
        }
        return min((int)citations.size() - l, citations[l]);
    }
};
