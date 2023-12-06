#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
 
// Number of vertices in the graph
#define V 23
 
// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}
 
// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the
                 // shortest
    // distance from src to i
 
    bool sptSet[V]; // sptSet[i] will be true if vertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized
 
    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)
 
            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    // print the constructed distance array
    printSolution(dist);
}
int main()
{
    
    int cost[23][23]={
{0,1,2,3,4,5,6,7,8,9,10,11,12,13,1,0,0,1,1,1,0,1,0},//arturo prat limite izquierdo
{1,0,1,2,3,4,5,6,7,8,9,10,11,12,1,1,1,1,1,1,1,1,1},//serrano
{2,1,0,1,2,3,4,5,6,7,8,9,10,11,1,1,1,1,1,1,1,1,1},//salas
{3,2,1,0,1,2,3,4,5,6,7,8,9,10,1,1,1,1,1,1,1,1,1},//angol
{4,3,2,1,0,1,2,3,4,5,6,7,8,9,1,1,1,1,1,1,1,1,1},//lincoyan
{5,4,3,2,1,0,1,2,3,4,5,6,7,8,1,1,1,1,1,1,1,1,1},//rengo
{6,5,4,3,2,1,0,1,2,3,4,5,6,7,1,1,1,1,1,1,1,1,1},//caupolican
{7,6,5,4,3,2,1,0,1,2,3,4,5,6,1,1,1,1,1,1,1,1,1},//anival pinto
{8,7,6,5,4,3,2,1,0,1,2,3,4,5,1,1,1,1,1,1,1,1,1},//colocolo
{9,8,7,6,5,4,3,2,1,0,1,2,3,4,1,1,1,1,1,1,1,1,1},//castellon
{10,9,8,7,6,5,4,3,2,1,0,1,2,3,1,1,1,1,1,1,1,1,1},//tucapel
{11,10,9,8,7,6,5,4,3,2,1,0,1,2,1,1,1,1,1,1,1,1,1},//orompello
{12,11,10,9,8,7,6,5,4,3,2,1,0,1,1,1,1,1,1,1,1,1,1},//ongolmo
{13,12,11,10,9,8,7,6,5,4,3,2,1,0,1,1,0,1,0,1,0,1,1},//paicavi limite derecho
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,2,3,4,5,6,7,8},//chacabuco limite abajo
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,2,3,4,5,6,7},//cochrane
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,0,1,2,3,4,5,6},//san martin
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,2,1,0,1,2,3,4,5},//ohiggins
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,3,2,1,0,1,2,3,4},//barros
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},//freire
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},//maipu
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},//carrera limite arriba
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}//diagonal ;
    dijkstra(cost, cost[0][0]);// podemos pedir inicio especifico pero llegaremos a una calle solamente no una direccion
    return 0;
}
