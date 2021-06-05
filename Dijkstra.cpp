#include <iostream>
using namespace std;
#define I 999999
#define N 8

void dijkstra(int source, int arr[N][N], int dist[N])
{
    int selected[N];
    for (int i = 0; i < N; i++)
    {
        selected[i] = 0;
        dist[i] = arr[source - 1][i];
    }
    dist[source - 1] = 0;
    selected[source - 1] = 1;
    int i = 2;
    while (i <= N)
    {
        int min = I;
        int next_key = 0;
        for (int j = 0; j < N; j++)
        {
            if ((selected[j]) == 0 && (dist[j] < min))
            {
                min = dist[j];
                next_key = j;
            }
        }
        selected[next_key] = 1;
        for (int j = 0; j < N; j++)
        {
            if ((selected[j] == 0) && (arr[next_key][j] != I))
            {
                if (dist[j] > min + arr[next_key][j])
                {
                    dist[j] = min + arr[next_key][j];
                }
            }
        }
        i++;
    }
}

int main()
{
    int source = 5;
    int cost[N][N] = {
        I,
        I,
        I,
        I,
        I,
        I,
        I,
        I,
        300,
        I,
        I,
        I,
        I,
        I,
        I,
        I,
        1000,
        800,
        I,
        I,
        I,
        I,
        I,
        I,
        I,
        I,
        1200,
        I,
        I,
        I,
        I,
        I,
        I,
        I,
        I,
        1500,
        I,
        250,
        I,
        I,
        I,
        I,
        I,
        1000,
        I,
        I,
        900,
        1400,
        I,
        I,
        I,
        I,
        I,
        I,
        I,
        1000,
        1700,
        I,
        I,
        I,
        I,
        I,
        I,
        I,
    };
    int dist[8] = {0};
    dijkstra(source, cost, dist);
    cout << "Vertex      Cost" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "   " << i + 1 << "        " << dist[i] << endl;
    }
}