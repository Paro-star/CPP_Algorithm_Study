#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Search
{
    private:
        vector<int> A;

        mutable vector<pair<int, int>> sorted_A;
        mutable bool is_sorted = false;
        void prepare_data() const
        {
            sorted_A.clear();
            for(int i = 0; i < A.size(); i++)
            {
                sorted_A.push_back({A[i], i});
            }
            sort(sorted_A.begin(), sorted_A.end());
            is_sorted = true;
        }
    public:
        void input(int value)
        {
            A.push_back(value);
            is_sorted = false;
        }
        const vector<int> &get_data() const
        {
            return A;
        }
        vector<int> linear_search(int x) const; // co the tra ve nhieu vi tri.
        int binary_search(int x) const; // chi tra ve mot vi tri.
        int interpolation_search(int x) const; // chi tra ve mot vi tri.
};



vector<int> Search::linear_search(int x) const
{
    vector<int> result;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] == x)
            result.push_back(i);
    }
    return result;
}

int Search::binary_search(int x) const
{
    if(A.empty())
        return -1;
    
    prepare_data();

    int result;
    int l = 0;
    int r = sorted_A.size() - 1;

    while(l <= r)
    {
        int m = (l + r) / 2;
        if(x == sorted_A[m].first)
        {
            result = sorted_A[m].second;
            return result;
        }
        if(x < sorted_A[m].first)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int Search::interpolation_search(int x) const
{
    if(A.empty())
        return -1;
    
    prepare_data();

    int l = 0;
    int r = sorted_A.size() - 1;
    int result;

    while(l <= r && x >= sorted_A[l].first && x <= sorted_A[r].first)
    {
        if(l == r)
        {
            if(sorted_A[l].first == x)
                return sorted_A[l].second;
            return -1;
        }

        int m = l + (((double)(r - l) / (sorted_A[r].first - sorted_A[l].first)) * (x - sorted_A[l].first));

        if(x == sorted_A[m].first)
        {
            result = sorted_A[m].second;
            return result;
        }
        if(x < sorted_A[m].first)
            r = m - 1;
        else 
            l = m + 1;
    }
    return -1;
}

void print_vector(const vector<int> &v)
{
    if(v.empty())
    {
        cout << "khong co du lieu" << endl;
        return ;
    }
    for(auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    Search A;
    int tmp;
    cout << "nhap gia tri cho mang: ";
    while(true)
    {
        cin >> tmp;
        if(tmp < 0)
            break;
        A.input(tmp);
    }

    print_vector(A.get_data());
    
    int x;
    cout << "nhap gia tri can tim: ";
    cin >> x;

    cout << "tim kiem kieu LinearSearch: " << endl;
    cout << "vi tri co gia tri " << x << " la: "; 
    print_vector(A.linear_search(x));

    cout << "tim kiem kieu BinarySearch: " << endl;
    cout << "vi tri co gia tri " << x << " la: " << A.binary_search(x) << endl; 

    cout << "tim kiem kieu interpolation_search: " << endl;
    cout << "vi tri co gia tri " << x << " la: " << A.interpolation_search(x) << endl; 

    system("pause");
    return 0;
}
