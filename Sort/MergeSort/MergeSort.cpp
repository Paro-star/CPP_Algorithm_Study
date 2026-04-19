//
// Created by duong on 4/19/2026.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums, int l, int m, int r) {
    vector<int> tmp;
    tmp.reserve(r - l);
    int i = l;
    int j = m;

    while (i < m && j < r) {
        if (nums[i] <= nums[j])
            tmp.push_back(nums[i++]);
        else
            tmp.push_back(nums[j++]);
    }

    while (i < m)
        tmp.push_back(nums[i++]);
    while (j < r)
        tmp.push_back(nums[j++]);

    copy(tmp.begin(), tmp.end(), nums.begin() + l);
}

void merge_sort(vector<int> &nums, int l, int r) {
    if (l >= r - 1)
        return;
    int m = l + (r - l) / 2;
    merge_sort(nums, l, m);
    merge_sort(nums, m, r);
    merge(nums, l, m, r);
}

int main() {
    vector<int> data;
    int x;

    cout << "Nhap lan luot cac gia tri can sap xep (Nhap ky tu bat ky de thoat): ";
    while (cin >> x) {
        data.push_back(x);
    }

    merge_sort(data, 0, data.size());

    cout << "Cac gia tri sau khi da sap xep la: ";
    for (auto i : data) {
        cout << i << " ";
    } cout << endl;

    return 0;
}