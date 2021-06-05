#include <iostream>
using namespace std;

int parent[7];
class Edge
{
public:
	int v1, v2, l;
};

void adjust(Edge *edge, int k, int e)
{
	int j;
	j = k + k;
	Edge item = edge[k - 1];

	while (j <= e)
	{
		if ((j < e) && (edge[j - 1].l > edge[j].l))
		{
			j++;
		}
		if (item.l <= edge[j - 1].l)
		{
			break;
		}
		edge[(j / 2) - 1] = edge[j - 1];
		j = j + j;
	}
	edge[(j / 2) - 1] = item;
}

void heapify(Edge *edge, int e)
{
	int half = 0;
	for (half = (e / 2); half >= 1; half--)
	{
		adjust(edge, half, e);
	}
}

int Find(int i)
{
	while (parent[i - 1] >= 0)
	{
		i = parent[i - 1];
	}
	return i;
}

void del(Edge *edge, int e)
{
	edge[0] = edge[e - 1];
	heapify(edge, e - 1);
	return;
}

int kruskal(Edge *edge, int v, int e, Edge *t)
{
	heapify(edge, e);
	for (int i = 0; i < v; i++)
	{
		parent[i] = -1;
	}
	int nvertex_in_t = 0;
	int mincost = 0;
	while (nvertex_in_t < v - 1 && e != 0)
	{
		Edge current;
		current = edge[0];
		del(edge, e);
		int j = Find(current.v1);
		int k = Find(current.v2);
		if (j != k)
		{
			t[nvertex_in_t] = current;
			nvertex_in_t++;
			mincost = mincost + current.l;
			parent[current.v1 - 1] = current.v2;
		}
		e--;
	}
	if (nvertex_in_t != v - 1)
	{
		cout << "No Spanning Tree is possible for this set of edges." << endl;
		return 0;
	}
	else
	{
		return mincost;
	}
}

int main()
{
	int v = 7;
	int e = 9;
	Edge *edge = new Edge[e];
	Edge *t = new Edge[v - 1];

	edge[0].v1 = 1;
	edge[0].v2 = 6;
	edge[0].l = 10;

	edge[1].v1 = 6;
	edge[1].v2 = 5;
	edge[1].l = 25;

	edge[2].v1 = 5;
	edge[2].v2 = 4;
	edge[2].l = 22;

	edge[3].v1 = 4;
	edge[3].v2 = 3;
	edge[3].l = 12;

	edge[4].v1 = 3;
	edge[4].v2 = 2;
	edge[4].l = 16;

	edge[5].v1 = 1;
	edge[5].v2 = 2;
	edge[5].l = 28;

	edge[6].v1 = 2;
	edge[6].v2 = 7;
	edge[6].l = 14;

	edge[7].v1 = 7;
	edge[7].v2 = 4;
	edge[7].l = 18;

	edge[8].v1 = 7;
	edge[8].v2 = 3;
	edge[8].l = 24;

	int mincost = kruskal(edge, v, e, t);
	cout << "vertex 1"
		 << "   "
		 << "vertex2"
		 << "   "
		 << "edge_weight\n";
	for (int i = 0; i < v - 1; i++)
	{
		cout << t[i].v1 << "            " << t[i].v2 << "            " << t[i].l << endl;
	}
	cout << "Mincost for the given set of edges is: " << mincost << endl;
	return 0;
}
