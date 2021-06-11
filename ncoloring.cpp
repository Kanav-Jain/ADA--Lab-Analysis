#include <iostream>
using namespace std;

#define N 5

void next_value(int graph[N][N], int x[N], int M, int k)
{
    while (true)
    {
        x[k - 1] = (x[k - 1] + 1) % (M + 1);
        if (x[k - 1] == 0)
        {
            return;
        }
        int j;
        for (j = 1; j <= N; j++)
        {
            if (graph[k - 1][j - 1] != 0 && x[k - 1] == x[j - 1])
            {
                break;
            }
        }
        if (j == N + 1)
        {
            return;
        }
    }
}

void ncoloring(int graph[N][N], int x[N], int k, int M)
{
    while (true)
    {
        next_value(graph, x, M, k);
        if (x[k - 1] == 0)
        {
            return;
        }
        if (k == N)
        {
            //print x[1..k]
            for (int i = 0; i < k; i++)
            {
                cout << x[i] << "  ";
            }
            cout << endl
                 << endl;
        }
        else
        {
            ncoloring(graph, x, k + 1, M);
        }
    }
}

int main()
{
    int graph[N][N] = {0, 1, 1, 0, 1,
                       1, 0, 1, 0, 1,
                       1, 1, 0, 1, 0,
                       0, 0, 1, 0, 1,
                       1, 1, 0, 1, 0};
    int k = 1;
    int x[N] = {0};
    int m = 3;
    ncoloring(graph, x, k, m);
}