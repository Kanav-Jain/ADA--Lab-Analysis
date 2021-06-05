#include <bits/stdc++.h>
using namespace std;
#define m 9
#define n 8

void print_LCS(int X[m], int b[m][n], int i = m, int j = n)
{
    if (m == 0 || n == 0)
    {
        return;
    }
    else
    {
        if (b[i - 1][j - 1] == 100)
        {
            print_LCS(X, b, i - 1, j - 1);
            cout << "   " << i - 1 << "-------->" << X[i - 1] << endl;
        }
        else if (b[i - 1][j - 1] == 102)
        {
            print_LCS(X, b, i - 1, j);
        }
        else if (b[i - 1][j - 1] == 101)
        {
            print_LCS(X, b, i, j - 1);
        }
    }
}

void LCS(int c[m + 1][n + 1], int X[m], int Y[n], int b[m][n])
{
    for (int i = 1; i < m + 1; i++)
    {
        c[i][0] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        c[0][i] = 0;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i - 1][j - 1] = 100; //100 is for diagnol
            }
            else
            {
                if (c[i - 1][j] >= c[i][j - 1])
                {
                    b[i - 1][j - 1] = 102; //102 is for up
                    c[i][j] = c[i - 1][j];
                }
                else
                {
                    b[i - 1][j - 1] = 101; //101 is for left
                    c[i][j] = c[i][j - 1];
                }
            }
        }
    }
    for (int k = 0; k < m; k++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << b[k][j] << "  ";
        }
        cout << endl;
    }
    cout << "index       value" << endl;
    print_LCS(X, b, m, n);
}

int main()
{
    int X[m] = {0, 1, 0, 1, 1, 0, 1, 1, 0};
    int Y[n] = {1, 0, 0, 1, 0, 1, 0, 1};
    int b[m][n];
    int c[m + 1][n + 1];
    LCS(c, X, Y, b);
}
