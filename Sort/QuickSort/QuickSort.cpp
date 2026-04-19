//
// Created by duong on 4/19/2026.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int Step = 0;

void Dump(const vector<int> &Obj) {
    for (auto i : Obj) {
        cout << i << " ";
    } cout << endl;
}


int Partition(vector<int> &Obj, int Low, int High) {
    cout << "Goi ham quick sort lan thu " << ++Step << endl;
    int Mid = Low + (High - Low) / 2;
    int pivot = Obj[Mid];
    int i = Low - 1;
    int j = High + 1;

    while (true) {
        while (Obj[++i] < pivot) { if (i == High) break; }
        while (Obj[--j] > pivot) { if (j == Low) break; }
        if (i >= j) break;

        swap(Obj[i], Obj[j]);
        Dump(Obj);
    }
    return j;
}

void QuickSort(vector<int> &Obj, int Low, int High) {
    if (Low < High) {
        int p = Partition(Obj, Low, High);
        QuickSort(Obj, Low, p);
        QuickSort(Obj, p + 1, High);
    }
}


int main() {
    vector<int> Data;
    int x;

    cout << "Nhap lan luot cac so can sap xep: ";
    while (cin >> x) {
        Data.push_back(x);
    }

    QuickSort(Data, 0, Data.size() - 1);


    return 0;
}