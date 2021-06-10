#include <iostream>
using namespace std;
#define n 6

void sum_of_subsets(int numbers[], int x[], int m, int sum, int k, int r)
{
    x[k - 1] = 1;
    if (sum + numbers[k - 1] == m)
    {
        cout << "Xi's       Numbers   " << endl;
        for (int i = 0; i < k; i++)
        {
            cout << x[i] << "------------>" << numbers[i] << endl;
        }
    }
    else if (sum + numbers[k - 1] + numbers[k] <= m)
    {
        sum_of_subsets(numbers, x, m, sum + numbers[k - 1], k + 1, r - numbers[k - 1]);
    }
    if (sum + r - numbers[k - 1] >= m && sum + numbers[k] <= m)
    {
        x[k - 1] = 0;
        sum_of_subsets(numbers, x, m, sum, k + 1, r - numbers[k - 1]);
    }
}

int main()
{
    int numbers[n] = {5, 10, 12, 13, 15, 18};
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        r += numbers[i];
    }
    int sum = 0, m = 30;
    int x[n] = {0};
    // for (auto c : x)
    // {
    //     cout << c;
    // }
    int k = 1;
    cout << "The required subsets are: " << endl;
    sum_of_subsets(numbers, x, m, sum, k, r);
    return 0;
}