#include <iostream>
#include <vector>

using namespace std;

int find_MEX(int n)
{   
    vector<bool> present(n + 1, false);
    for(int i = 0; i < n; i++)
    {
        long long val;
        cin >> val;
        if(val >= 0 && val <= n)
        {
            present[val] = true;
        }
    }

    for(int i = 0; i <= n; i++)
    {
        if(!present[i])
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << find_MEX(n);
}