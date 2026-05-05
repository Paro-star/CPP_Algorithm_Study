//
// Created by duong on 5/5/2026.
//
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>

using namespace std;
struct TNode {
    int key;
    TNode *left, *right;
};

typedef TNode * TREE;

void CreateTree(TREE &t) {
    t = NULL;
}

TNode * CreateTNode(int x) {
    TNode * p = new TNode;
    if (p == NULL) return NULL;
    p->left = p->right = NULL;
    p->key = x;
    return p;
}

void InsertNode(TREE &t, int x) {
    TNode *p = CreateTNode(x);

    if (t == NULL) {
        t = p;
        return;
    }
    TREE q = t;
    while (q != NULL) {
        if (x == q->key) return;
        if (x > q->key) {
            if (q->right == NULL) {
                q->right = p;
                return;
            }
            q = q->right;
        }
        else {
            if (q->left == NULL) {
                q->left = p;
                return;
            }
            q = q->left;
        }
    }
}

void LoadTree(TREE &t) {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        InsertNode(t, k);
    }
}

int ComparisonCount(TREE, int);

int main()
{
    vector<int> keys;
    TREE t;
    CreateTree(t);
    LoadTree(t);
    int m, k;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        cout << ComparisonCount(t, k) << endl;
    }
    return 0;
}

int ComparisonCount(TREE t, int k) {
    if (t == NULL) return 0;
    if (t->key == k) return 1;
    if (t->key < k) return 1 + ComparisonCount(t->right, k);
    return 1 + ComparisonCount(t->left, k);
}

/*
int ComparisonCount(TREE t, int k) {
    int count = 0;
    TNode* curr = t;

    while (curr != NULL) {
        count++; // Tăng biến đếm mỗi khi thực hiện so sánh tại một nút
        if (curr->key == k) {
            return count;
        }
        if (k > curr->key) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return count; // Trả về tổng số lần so sánh ngay cả khi không tìm thấy
}
 */

