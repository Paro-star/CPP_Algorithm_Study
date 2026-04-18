#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(const vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    while(left < right)
    {
        if(arr[left] != arr[right])
            return false;
        left++;
        right--;
    }
    return true;
}

void set_array(vector<int> &arr, int x)
{
    while(x > 0)
    {
        arr.push_back(x % 10);
        x /= 10;
    }
}

void print(const vector<int> &arr)
{
    for(int i = arr.size() - 1; i >= 0; i--)
    {
        cout << arr[i];
    }
    cout << endl;
}


void add(vector<int> &arr)
{
    vector<int> rev_arr = arr;
    reverse(rev_arr.begin(), rev_arr.end());

    int temp = 0;
    int n = arr.size();

    for(int i = 0; i < n; i++)
    {
        int sum = arr[i] + rev_arr[i] + temp;
        arr[i] = sum % 10;
        temp = sum /= 10;
    }

    if(temp > 0)
    {
        arr.push_back(temp);
    }
}

int main()
{
    vector<int> A;
    
    int x;
    cin >> x;

    int n, m;
    cin >> n >> m;

    set_array(A, x);

    int steps = 0;
    while(steps < n && A.size() < m && isPalindrome(A) == false)
    {        
        add(A);
        steps ++;
    }
    if(steps < n)
    {
        cout << "NO\n" << steps << " ";
        print(A);
    }
    else
    {
        cout << "YES\n" << steps << " ";
        print(A);
    }
    system("pause");
    return 0;
}