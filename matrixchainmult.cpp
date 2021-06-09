#include <bits/stdc++.h>
using namespace std;
#define I 99999
#define N 6

void print_optimal_parenthesis(int s[N][N], int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        print_optimal_parenthesis(s, i, s[i - 1][j - 1]);
        print_optimal_parenthesis(s, s[i - 1][j - 1] + 1, j);
        cout << ")";
    }
}

void matrixchainmultiplication(int p[N + 1])
{
    int matrix[N][N], s[N][N];
    for (int i = 0; i < N; i++)
    {
        matrix[i][i] = 0;
        s[i][i] = 0;
    }
    for (int l = 2; l <= N; l++)
    {
        for (int i = 1; i <= N - l + 1; i++)
        {
            int j = i + l - 1;
            matrix[i - 1][j - 1] = I;
            for (int k = i; k < j; k++)
            {
                int val = matrix[i - 1][k - 1] + matrix[k][j - 1] + p[i - 1] * p[k] * p[j];
                if (val < matrix[i - 1][j - 1])
                {
                    matrix[i - 1][j - 1] = val;
                    s[i - 1][j - 1] = k;
                }
            }
        }
    }
    // for (int i = 1; i <= N; i++)

    // {
    //     for (int j = 1; j <= N; j++)
    //     {
    //         if (j < i)
    //         {
    //             cout << "       ";
    //         }
    //         else
    //         {
    //             cout << matrix[i - 1][j - 1] << "   ";
    //         }
    //     }
    //     cout << endl;
    // }
    cout << "Scalar multiplications are: " << matrix[0][5] << endl;
    print_optimal_parenthesis(s, 1, N);
}

int main()
{
    int p[N + 1] = {33, 35, 15, 5, 10, 20, 25}; //{22, 12, 35, 28, 24};
    matrixchainmultiplication(p);
}