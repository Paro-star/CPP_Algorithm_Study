#include <iostream>

using namespace std;

int count_folds(long long paper, long long env)
{
    int count = 0;
    while(paper > env)
    {
        paper /= 2;
        count ++;
    }
    return count;
}

int main()
{
    long long n, m, h, w;
    cin >> n >> m >> h >> w;
    int option1 = count_folds(n, h) + count_folds(m, w);
    int option2 = count_folds(n, w) + count_folds(m, h);
    cout << min(option1, option2);
    system("pause");
    return 0;
}