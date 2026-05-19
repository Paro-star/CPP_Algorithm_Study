//
// Created by duong on 5/19/2026.
//
#include <iostream>
#include <vector>

using namespace std;

int h(int k, int M) {
    return k % M;
}

int main() {
    int n, M;
    cin >> n >> M;
    int count = 0;
    vector<bool> table(M, true);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int _h = h(k, M);
        if (table[_h]) table[-_h] = false;
        else count ++;
    }
    ((double(count) / n) <= 0.33) ? cout << "GOOD" : cout << "BAD";
    return 0;
}