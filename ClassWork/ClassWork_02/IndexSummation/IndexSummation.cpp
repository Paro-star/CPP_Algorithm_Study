#include <iostream>

using namespace std;

int cal_sum(int *a, int *b, int k)
{
    int sum = 0;
    for(int i = 0; i < k; i++)
    {
        sum += *(a + *(b + i));
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;
    int *a = (int*)malloc(n * sizeof(int));
    int i;
    for(int i = 0; i < n; i++)
    {
        cin >> *(a + i);
    }
    int k;
    cin >> k;
    int *b = (int*)malloc(k * sizeof(int));
    for(int i = 0; i < k; i++)
    {
        cin >> *(b + i);
    }
 
    cout << cal_sum(a, b, k);

    free(a);
    free(b);
    system("pause");
    return 0;

}