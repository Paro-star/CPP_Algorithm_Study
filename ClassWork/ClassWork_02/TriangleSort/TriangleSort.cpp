//
// Created by duong on 4/20/2026.
//

#include <cmath>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct Triangle {

    Triangle(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}

    int a, b, c;
    double s;

    void calS() {
        double p = (a + b + c) / 2.0;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
    }

    bool isValid() {
        if (a + b > c && b + c > a && c + a > b) {
            return true;
        }
        return false;
    }
};

void Heapify(vector<Triangle> &ls, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && ls[largest].s > ls[left].s) {
        largest = left;
    }

    if (right < n && ls[largest].s > ls[right].s) {
        largest = right;
    }

    if (largest != i) {
        swap (ls[largest], ls[i]);
        Heapify(ls, n, largest);
    }
}

void HeapSort(vector<Triangle> &ls, int n) {
    //Tao MinHeap
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(ls, n, i);
    }

    //Sort
    for (int i = n - 1; i > 0; i--) {
        swap (ls[0], ls[i]);
        Heapify(ls, i, 0);
    }

}

int main() {

    //Toi uu hoa nhap xuat.
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //Nhap so luong tam giac va khoi tao mang Tam Giac chua n phan tu.
    cout << "Nhap so luong tam giac\n";
    int n;
    cin >> n;
    Triangle *ls = new Triangle[n];
    vector<Triangle> tmp; // Mang phu de luu tam giac hop le.

    //Nhap gia tri 3 canh cho tam giac.
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri cho tam giac thu " << i + 1 << "\n";
        cin >> ls[i].a >> ls[i].b >> ls[i].c;
        if (ls[i].isValid()) {
            ls[i].calS();
            tmp.push_back(ls[i]);
        }
    }

    HeapSort(tmp, tmp.size());

    // Dien lai cac tam giac vao mang goc.
    int step = 0;
    for (int i = 0; i < n; i++) {
        if (ls[i].isValid()) {
            ls[i] = tmp[step++];
        }
    }

    //In cac tam giac ra man hinh.
    for (int i = 0; i < n; i++) {
        cout << ls[i].a << " " << ls[i].b << " " << ls[i].c << "\n";
    }
    return 0;
}
