//
// Created by duong on 5/16/2026.
//
#include <iostream>
#include <vector>

using namespace std;

int hash_func(int k, int m) {
    return k % m;
}

int probing(int k, int m, int i) {
    return (hash_func(k, m) + i * i) % m;
}

struct HT {
    vector<pair<int, int>> st;
    const int empty = -1;
    const int occupied = -2;
    const int deleted = -3;
    HT(int m = 1000003) {
        st.resize(m, {empty, -1});
    }
    int insert(int x) {
        int index = find(x);
        if (index != -1) {
            return index;
        }

        int i = 0;
        while (i < st.size()) {
            int j = probing(x, st.size(), i);
            if (st[j].first == empty || st[j].first == deleted) {
                st[j].second = x;
                st[j].first = occupied;
                return j;
            }
            i += 1;
        }
        return -1;
    }

    int find(int x) {
        int i = 0;
        while (i < st.size()) {
            int j = probing(x, st.size(), i);
            if (st[j].first == empty) {
                return empty;
            }
            if (st[j].first == occupied && st[j].second == x) {
                return j;
            }
            i += 1;
        }
        return -1;
    }

    int remove(int x){
        int i = 0;
        while (i < st.size()) {
            int j = probing(x, st.size(), i);
            if (st[j].first == empty) {
                return -1;
            }
            if (st[j].first == occupied && st[j].second == x) {
                st[j].first = deleted;
                return deleted;
            }
            i += 1;
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m = 1000003;    // m must be a prime number.
    HT a(m);
    int choice, x;
    while (cin >> choice && choice != 0) {
        cin >> x;
        if (choice == 1) {
            a.insert(x);
        }
        else if (choice == 2) {
            auto temp = a.find(x);
            if (temp != -1) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (choice == 3) {
            if (a.remove(x) == -3) {
                cout << "REMOVE SUCCESS!\n";
            }
            else {
                cout << "REMOVE FAIL!\n";
            }
        }
    }

    return 0;
}