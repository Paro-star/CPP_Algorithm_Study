//
// Created by duong on 4/21/2026.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void solve(string path) {
    vector<string> stack;
    stringstream ss(path);
    string part;

    // Tách chuỗi theo dấu '/'
    while (getline(ss, part, '/')) {
        if (part == "" || part == ".") {
            continue;
        } else if (part == "..") {
            if (!stack.empty()) stack.pop_back();
        } else {
            stack.push_back(part);
        }
    }

    // In kết quả
    if (stack.empty()) {
        cout << "/" << endl;
        return;
    }
    for (const string& s : stack) {
        cout << "/" << s;
    }
    cout << endl;
}

int main() {
    string line;
    while (getline(cin, line) && line != "END") {
        if (line.empty()) continue;
        solve(line);
    }
    return 0;
}