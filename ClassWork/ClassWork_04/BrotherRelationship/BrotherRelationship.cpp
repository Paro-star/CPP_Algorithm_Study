//
// Created by duong on 5/5/2026.
//
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using namespace std;

struct TNode{
    int key;
    TNode* pLeft;
    TNode* pRight;
};

struct Tree{
    TNode* root;
};

void CreateTree(Tree &T)
{
    T.root = NULL;
}

TNode* CreateTNode(int x) {
    TNode* p;
    p = new TNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(Tree &, int);
bool isBrother(Tree, int, int);


void run(int q, Tree T){
    //###INSERT CODE HERE -
    struct Local {
        static TNode* FindFather(TNode* r, int x, TNode* Father = (TNode*)-1) {
            if (r == NULL) return NULL;
            if (r->key == x) return Father;
            if (r->key < x) return FindFather(r->pRight, x, r);
            return FindFather(r->pLeft, x, r);
        }
    };

    while (q--) {
        int a, b;
        cin >> a >> b;

        TNode * p1 = Local::FindFather(T.root, a);
        TNode * p2 = Local::FindFather(T.root, b);

        (p1 == p2 && p1 != NULL && p1 != (TNode*)-1 && a != b) ?
            cout << a << " va " << b << " la anh em\n" :
            cout << a << " va " << b << " khong phai la anh em\n";
    }
}



void Insert(Tree &T, int x) {
    TNode *p = CreateTNode(x);
    if (T.root == NULL) {
        T.root = p;
        return;
    }
    TNode* q = T.root;
    while (q != NULL) {
        if (x == q->key) return;
        if (x > q->key) {
            if (q->pRight == NULL) {
                q->pRight = p;
                return;
            }
            q = q->pRight;
        } else {
            if (q->pLeft == NULL) {
                q->pLeft = p;
                return;
            }
            q = q->pLeft;
        }
    }
}

void Trash() {
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree T;
    CreateTree(T);
    int n; cin >> n;
    int data;
    while(n != 0) {
        cin >> data;
        Insert(T, data);
        n--;
    }
    int q; cin >> q;
    run(q, T);

    return 0;
}
