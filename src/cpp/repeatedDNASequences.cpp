/*
 *All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
 * */
#include "header.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> hash;
        vector<string> result;
        if (s.size() < 11) { return result; }
        int table[26] = { 0 };
        table['C' - 'A'] = 1;
        table['G' - 'A'] = 2;
        table['T' - 'A'] = 3;
        int i = 0, h = 0;
        while (i < 9) {
            h = ((h << 2) | table[s[i++] - 'A']) & 0x000fffff;
        }
        while (i < s.size()) {
            if (hash[(h = ((h << 2) | table[s[i] - 'A']) & 0x000fffff)]++ == 1) {
                result.push_back(s.substr(i - 9, 10));
            }
            i++;
        }
        return result;
    }
};

int main(int argc, char **argv) {
    print_vector(Solution().findRepeatedDnaSequences(argv[1]));
    return 0;
}
