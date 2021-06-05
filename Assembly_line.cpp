#include <iostream>
using namespace std;

#define N 6

int assembly_line(int cost[2][N], int time[2][N - 1], int entry[2], int exit[2])
{
    int f1[N], f2[N], l1[N], l2[N];
    f1[0] = cost[0][0] + entry[0];
    f2[0] = cost[1][0] + entry[1];
    l1[0] = 1;
    l2[0] = 2;
    for (int i = 1; i < N; i++)
    {
        if (f1[i - 1] + cost[0][i] > f2[i - 1] + time[1][i - 1] + cost[0][i])
        {
            f1[i] = f2[i - 1] + time[1][i - 1] + cost[0][i];
            l1[i] = 2;
        }
        else
        {
            f1[i] = f1[i - 1] + cost[0][i];
            l1[i] = 1;
        }
        if (f2[i - 1] + cost[1][i] > f1[i - 1] + time[0][i - 1] + cost[1][i])
        {
            f2[i] = f1[i - 1] + time[0][i - 1] + cost[1][i];
            l2[i] = 1;
        }
        else
        {
            f2[i] = f2[i - 1] + cost[1][i];
            l2[i] = 2;
        }
    }
    int f1_mincost = f1[N - 1] + exit[0];
    int f2_mincost = f2[N - 1] + exit[1];
    if (f1_mincost < f2_mincost)
    {
        cout << "We have gone through the path: ";
        for (int i = 0; i < N; i++)
        {
            cout << l1[i] << " ";
        }
        cout << endl;
        return f1_mincost;
    }
    else
    {
        cout << "We have gone through the path: ";
        for (int i = 0; i < N; i++)
        {
            cout << l2[i] << " ";
        }
        cout << endl;
        return f2_mincost;
    }
}

int main()
{
    int entry[2] = {2, 4};
    int exit[2] = {3, 2};
    int cost_arr[2][N] = {
        7,
        9,
        3,
        4,
        8,
        4,
        8,
        5,
        6,
        4,
        5,
        7,
    };

    int time[2][N - 1] = {
        2, 3, 1, 3, 4,
        2, 1, 2, 2, 1};
    int mincost = assembly_line(cost_arr, time, entry, exit);
    cout << "The mincost is: " << mincost << endl;
    return 0;
}
