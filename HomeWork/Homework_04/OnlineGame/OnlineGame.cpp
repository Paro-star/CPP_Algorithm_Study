//
// Created by duong on 5/16/2026.
//
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_set<int> st;
    int choice, x;
    while (cin >> choice && choice != 0) {
        cin >> x;
        if (choice == 1) {
            // Add
            st.insert(x);
        }
        else if (choice == 2) {
            // Find
            if (st.find(x) != st.end()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (choice == 3) {
            // Delete
            auto it = st.find(x);
            if (it != st.end()) {
                st.erase(it);
            }
        }
    }
    return 0;
}