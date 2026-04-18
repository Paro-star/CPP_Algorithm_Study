#include <iostream>
#include <vector>
#include <limits>

class VECTOR 
{
    private:
        std::vector<int> A;
    public:
        const std::vector<int> &get_data() const 
        {
            return A;
        }
        void add_value(int value) 
        {
            A.push_back(value);
        }
        void selection_sort();
        void insertion_sort();
        std::vector<int> counting_sort();
        int max_value() const;
        //int min_value() const;
};

void VECTOR::selection_sort() 
{
    if(A.empty())
        return;
    size_t n = A.size();
    for(size_t i = 0; i < n - 1; ++i)
    {
        size_t min_idx = i;

        for(size_t j = i + 1; j < n; ++j)
        {
            if(A[min_idx] > A[j])
            {
                min_idx = j;
            }
            
        }

        if(min_idx != i)
        {
            std::swap(A[i], A[min_idx]);
        }
    }
}

void VECTOR::insertion_sort()
{
    int n = A.size();
    for(int i = 1; i < n; i++)
    {
        int k = i - 1;
        int e = A[i];
        while(k >= 0 && e < A[k])
        {
            {
                A[k + 1] = A[k];
                k = k - 1;
            }
        }
        A[k + 1] = e; 
    }
}

std::vector<int> VECTOR::counting_sort()
{
    size_t n = A.size();
    int max_val = this->max_value();
    std::vector<int> B(max_val + 1, 0);
    std::vector<int> C(n);
    for(int i = 0; i < n; i++)
    {
        B[A[i]] += 1;
    }
    for(int i = 1; i < (max_val + 1); i++)
    {
        B[i] += B[i - 1];
    }
    for(int i = n - 1; i >= 0; i--)
    {
        C[B[A[i]] - 1] = A[i];
        B[A[i]] --;
    }
    return C;
}

int VECTOR::max_value() const
{
    int max = A[0];
    for(size_t i = 1; i < A.size(); i++)
    {
        if(max < A[i])
            max = A[i];
    }
    return max;
}


/*
int VECTOR::min_value() const
{
    int min = A[0];
    for(size_t i = 1; i < A.size(); i++)
    {
        if(min > A[i])
            min = A[i];
    }
    return min;
}
*/





void print_vector(const std::vector<int> &A)
{
    for(size_t i = 0; i < A.size(); i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
}

int main() 
{
    VECTOR A;

    int tmp;
    std::cout << "Nhap gia tri cho danh sach (nhap mot chu cai bat ky de dung lai): ";
    while(std::cin >> tmp)
    {
        A.add_value(tmp);
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    // truoc khi sap xep;
    VECTOR B = A;
    std::cout << "SELECTION_SORT \n";
    std::cout << "truoc khi sap xep: ";
    print_vector(B.get_data());

    B.selection_sort();

    //sau khi sap xep
    std::cout << "sau khi sap xep: ";
    print_vector(B.get_data());


    VECTOR C = A;
    std::cout << "INSERTION_SORT \n";
    std::cout << "truoc khi sap xep: ";
    print_vector(C.get_data());

    C.insertion_sort();

    //sau khi sap xep
    std::cout << "sau khi sap xep: ";
    print_vector(C.get_data());

    VECTOR D = A;
    std::cout << "COUNTING_SORT \n";
    std::cout << "truoc khi sap xep: ";
    print_vector(D.get_data());


    //sau khi sap xep
    std::cout << "sau khi sap xep: ";
    print_vector(D.counting_sort());

    std::cin.get();
    return 0;
}