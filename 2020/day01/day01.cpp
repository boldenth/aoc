// day01.cpp
// Thomas Bolden



#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <algorithm>
using std::sort; using std::find;

#include <map>
using std::map;

#include <fstream>
using std::ofstream; using std::ifstream;

#include <sstream>
using std::ostringstream;

#include "day01.h"

const int target = 2020;

struct pair {
    int first;
    int second;
};

struct triplet {
    int first;
    int second;
    int third;
};

pair two_sum() {
    map<int, int> hash;
    for (int i = 0; i < (sizeof(g_values) / sizeof(*g_values)); i++) {
        auto it = hash.find(target - g_values[i]);
        if (it == hash.end()) {
            hash.emplace(g_values[i], i);
        } else {
            return {it->second, i};
        }
    }
}

triplet three_sum() {
    int size = (sizeof(g_values) / sizeof(*g_values));
    for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
    for (int k = 0; k < size; k++) {
        int first = g_values[i];
        int second = g_values[j];
        int third = g_values[k];
        if ((first + second + third) == target) {
            return {i, j, k};
        }
    }
}

int main() {
    pair sum_indices = two_sum();
    cout << g_values[sum_indices.first] << endl;
    cout << g_values[sum_indices.second] << endl;
    cout << "product: " << g_values[sum_indices.first] * g_values[sum_indices.second] << endl;

    triplet sum_indices_3 = three_sum();
    cout << "product: " << g_values[sum_indices_3.first] * g_values[sum_indices_3.second] * g_values[sum_indices_3.third] << endl;

    return 0;
}
