//
// Created by duong on 4/21/2026.
//

#include <iostream>

using namespace std;

struct Node {
    int Value;
    Node *Next;
    Node (int v = 0, Node *Next = nullptr) : Value(v), Next(Next) {};
};

struct List {
    Node *Head = nullptr;
    Node *Tail = nullptr;
    int Size = 0;
};

void AddHead(List &l, int x) {
    l.Head = new Node(x, l.Head);
    if (l.Tail == nullptr)
        l.Tail = l.Head;
    l.Size ++;
}

void AddTail(List &l, int x) {
    Node *Temp = new Node(x);
    if (l.Tail == nullptr) {
        l.Tail = l.Head = Temp;
    }
    else {
        l.Tail->Next = Temp;
        l.Tail = Temp;
    }
    l.Size ++;
}

void AddAfter(List &l, int a, int b) {
    Node *Trav = l.Head;
    while (Trav != nullptr && Trav->Value != a) {
        Trav = Trav->Next;
    }
    if (Trav == nullptr)
        AddHead(l, b);
    else {
        Node *NewNode = new Node(b, Trav->Next);
        Trav->Next = NewNode;
        if (Trav == l.Tail)
            l.Tail = NewNode;
    }
    l.Size ++;
}

void Rotate(List &l, int k) {
    if (l.Head == nullptr || k % l.Size == 0) return;
    k %= l.Size;
    Node *Trav = l.Head;
    for (int i = 0; i < k - 1; i++) {
        Trav = Trav->Next;
    }
    l.Tail->Next = l.Head;
    l.Head = Trav->Next;
    Trav->Next = nullptr;
    l.Tail = Trav;
}

void DUMP(const List &l) {
    Node *Trav = l.Head;
    while (Trav != nullptr) {
        cout << Trav->Value << " ";
        Trav = Trav->Next;
    }
    cout << "\n";
}

int main() {
    int choice;
    int x, a, b, k;
    List l;

    while (cin >> choice && choice != 4) {
        if (choice == 0) {
            //Them vao dau ds
            cin >> x;
            AddHead(l, x);
        }
        else if (choice == 1) {
            //Them vao cuoi ds
            cin >> x;
            AddTail(l, x);
        }
        else if (choice == 2) {
            //Tim vi tri dau tien ma a xuat hien trong ds sau do them b sau so nay
            //, neu khong co thi them b vao dau ds.
            cin >> a >> b;
            AddAfter(l, a, b);
        }
        else if (choice == 3) {
            //Di chuyen k phan tu dau tien cua ds ve cuoi
            cin >> k;
            Rotate(l, k);
        }
    }
    DUMP(l);
    return 0;
}