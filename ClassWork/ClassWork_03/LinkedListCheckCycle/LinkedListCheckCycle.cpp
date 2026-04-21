//
// Created by duong on 4/21/2026.
//

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
###End banned keyword*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
    unsigned int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}
void add_tail(List &l, int x){
    Node*p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.head == NULL){
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

bool check_cycle(List l){

    if (l.head == NULL) return false;

    Node *truoc = l.head;
    Node *sau = l.head;

    while (truoc != NULL && truoc->next != NULL) {
        truoc = truoc->next->next;
        sau = sau->next;
        if (sau == truoc)
            return true;
    }
    return false;
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int n; cin >> n;

    //Input list
    List l; list_initializing(l);
    int x;
    do{
        cin >> x;
        add_tail(l, x);
    } while(x != 0);


    //Create a loop if input call for it
    int i, j;
    cin >> i >> j;
    x = i <= j;

    if (x) {
        Node *pi, *pj, *p = l.head;
        for(int c = 0; p != NULL;){
            if (c == i) pi = p;
            if (c == j) pj = p;

            p = p->next;
            c++;
        }
        pj->next = pi;
    }

    if(check_cycle(l) != x) cout << "WRONG";

    //All the node before the start of the loop must remain intact
    Node *p = l.head;
    for(i = 0; i <= j; i++, p = p->next){
        cout << p->val << endl;
    }

    return 0;
}
