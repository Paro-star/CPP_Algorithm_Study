#include <iostream>

void Nhap(int *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cin >> A[i];
    }
}

void Xuat(int *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
}

void insertion_sort(int *A, int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            Xuat(A, n);
            j -= 1;
        }
        A[j + 1] = key;
        Xuat(A, n);
    }
}


int main()
{
    int n;
    std::cin >> n;
    int *A = new int[n];

    Nhap(A, n);
    insertion_sort(A, n);

    system("pause");
    return 0;
}