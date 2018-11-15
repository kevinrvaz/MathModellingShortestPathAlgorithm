#include <stdio.h>
#include <limits.h>
#define V 21

int minDistance(int dist[],
                bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false &&
                   dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printPath(int parent[], int j)
{
    if (parent[j] == - 1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}

int printSolution(int dist[], int n,
                      int parent[])
{
    int src = 0;
    printf("Vertex              Distance\tPath");
    for (int i = 1; i < V; i++)
    {
        printf("\n%d -> %d             %d\t\t%d ",
                      src, i, dist[i], src);
        printPath(parent, i);
    }
    printf("\n");
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    int parent[V]; 
    for (int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;   
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    printSolution(dist, V, parent);
}

// Driver Code
int main()
{
    // Math model graph
    int graph[V][V] = {
	 // 0 1 2 3 4 5 6 7 8 9 1011121314151617181920
        {0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//0
        {5,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},//1
        {0,2,0,5,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//2
        {0,0,5,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//3
        {0,0,0,5,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//4
        {0,0,0,0,2,0,5,0,0,0,8,0,0,0,0,0,0,0,0,0,0},//5
        {0,0,4,0,0,5,0,3,0,0,8,0,0,0,0,0,0,0,0,2,0},//6
        {0,0,0,0,0,0,3,0,2,0,0,0,0,0,0,5,0,0,0,0,0},//7
        {0,0,0,0,0,0,0,2,0,3,0,0,0,1,0,0,0,0,0,0,0},//8
        {0,0,0,0,0,0,0,0,3,0,1,6,0,0,0,0,0,0,0,0,0},//9
        {0,0,0,0,0,8,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},//10
        {0,0,0,0,0,0,0,0,0,6,0,0,2,0,0,0,0,0,0,0,0},//11
        {0,0,0,0,0,0,0,0,0,0,0,2,0,6,0,0,0,0,0,0,0},//12
        {0,0,0,0,0,0,0,0,1,0,0,0,6,0,3,0,0,0,0,0,0},//13
        {0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,6,0,0,0,0,0},//14
        {0,0,0,0,0,0,0,5,0,0,0,0,0,0,6,0,2,0,0,0,0},//15
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,3,0,0,0},//16
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,1,0,0},//17
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1},//18
        {0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,4,0,0,1,0,0},//19
        {0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},//20
                             };

    dijkstra(graph, 0);
    return 0;
}
