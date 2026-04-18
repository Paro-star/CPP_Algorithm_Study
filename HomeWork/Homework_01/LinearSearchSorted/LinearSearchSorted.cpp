/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
vector
###End banned keyword*/

#include <iostream>

using namespace std;
#define MAXN 150000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void ChenTang(int x, int *A, int &n)
{
    int i = 0;
    while(i < n)
    {
        if(A[i] > x)
            break;
        i++;
    }

    for(int j = n; j > i; j--)
    {
        A[j] = A[j - 1];
    }
    A[i] = x;
    n++;
}


void XuatMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN];
    int x; cin >> x;
    int n; cin >> n;

    NhapMang(a, n);

    ChenTang(x, a, n);

    XuatMang(a, n);

    return 0;
}

