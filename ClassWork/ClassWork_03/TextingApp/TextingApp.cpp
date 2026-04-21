//
// Created by duong on 4/21/2026.
//
#include <iostream>
#include <vector>

using namespace std;

int count_mes(const vector<int> &data, int nums) {
    if (data.empty())
        return 0;
    int text = 0;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == nums)
            text += 1;
    }
    return text;
}
int main() {
    int unsigned k, n;
    cin >> k >> n;
    int nums;
    vector<int> total_text;

    while (n--) {
        cin >> nums;
        total_text.push_back(nums);
    }

    int step = 0;
    int back = total_text.size() - 1;
    vector<int> al_pop;

    while (step < k && back >= 0) {
        if (count_mes(al_pop, total_text[back])) {
            back --;
            continue;
        }

        al_pop.push_back(total_text[back]);

        int mes = count_mes(total_text, total_text[back]);
        cout << total_text[back];
        if (mes != 1) {
            cout << "(" << mes << ")" << " ";
        }
        else
            cout << " ";
        back --;
        step ++;
    }
    return 0;
}
