#include <iostream>
#include <cmath>
using namespace std;
#define N 4
int count = 1;

bool place(int x[], int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        if (x[j - 1] == i || abs(x[j - 1] - i) == abs(j - k))
            return false;
    }
    return true;
}

void print_chessboard(int x[], int chessboard[N][N])
{
    cout << "___"
         << "___"
         << "___"
         << "___" << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (x[i - 1] == j)
                cout << "| Q";
            else
                cout << "|  ";
        }
        cout << "|";
        cout << endl;
        cout << "___"
             << "___"
             << "___"
             << "___" << endl;
    }
}

void nqueens(int x[], int chessboard[N][N], int k)
{
    for (int i = 1; i <= N; i++)
    {
        if (place(x, k, i))
        {
            x[k - 1] = i;
            if (k == N)
            {
                cout << "Solution number " << count << " is:  ";
                for (int j = 0; j < k; j++)
                {
                    cout << x[j] << "   ";
                }
                cout << endl
                     << endl;
                count += 1;
                print_chessboard(x, chessboard);
                cout << endl
                     << endl
                     << endl;
            }
            else
            {
                nqueens(x, chessboard, k + 1);
            }
        }
    }
}

int main()
{
    int x[N] = {0};
    int chessboard[N][N];
    int k = 1;
    nqueens(x, chessboard, k);
}