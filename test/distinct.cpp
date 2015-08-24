#include "..\src\header.h"

vector<int> distinct(vector<int> array) {
    vector<int> res;
    for (int i = 0; i < array.size(); i++) {
        for (int j = i + 1; j < array.size(); j++) {
            if (array[i] == array[j]) j = ++i;
        }
        res.push_back(array[i]);
    }
    return res;
}

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++)
        nums.push_back(atoi(argv[i]));
    print_vector(distinct(nums));
    return 0;
}
