#include <bits/stdc++.h>
using namespace std;

#define N 5
#define I 9999999

int minimum(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

void shortest_path(int cost[N][N], int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = cost[i][j];
        }
    }
    for (int A = 1; A <= 5; A++)
    {
        int k = A - 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = minimum(arr[i][j], arr[i][k] + arr[k][j]);
                // cout << arr[i][j] << " ";
            }
            // cout << endl;
        }
        // cout << "\n\n\n";
    }
}

int main()
{
    int cost[N][N] = {
        0, 10, 50, 65, I,
        I, 0, 30, I, 4,
        I, I, 0, 20, 44,
        I, 70, I, 0, 23,
        6, I, I, I, 0};
    int arr[N][N];
    shortest_path(cost, arr);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}