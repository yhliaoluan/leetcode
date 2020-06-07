/*
 *Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 * */

#include "header.h"

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string s[3] = { "Thousand", "Million", "Billion" };
        string res;
        for (int i = 0; i < 3; i++) {
            int val = num % 1000;
            num /= 1000;
            if (num == 0) break;
            res.insert(" ").insert(s[i]).insert(" ");
        }
    }
    string unit(int u) {
        string words[9] = { "One", "Two", "Three", "Four", "Five", "Six",
            "Seven", "Eight", "Nine" };
        return words[u];
    }
    string decade_special(int d) {
        string words[10] = { "Ten", "Eleven", "Twelve", "Thirteen", 
            "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
            "Ninteen" };
        return words[d];
    }
    string decade(int d) {
        string words[8] = { "Twenty", "Thirty", "Fourty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninty" };
        return words[d];
    }
};
