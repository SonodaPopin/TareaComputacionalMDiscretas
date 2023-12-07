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
 int to_int(char c[20]){
    if(strcmp(c,"Arturo Prat")==0) return 0;//desde art prat
    if(strcmp(c,"Serrano")==0) return 1;
    if(strcmp(c,"Salas")==0) return 2;
    if(strcmp(c,"Angol")==0) return 3;
    if(strcmp(c,"Lincoyan")==0) return 4;
    if(strcmp(c,"Rengo")==0) return 5;
    if(strcmp(c,"Caupolican")==0) return 6;
    if(strcmp(c,"Anival Pinto")==0) return 7;
    if(strcmp(c,"Colo Colo")==0) return 8;
    if(strcmp(c,"Castellon")==0) return 9;
    if(strcmp(c,"Tucapel")==0) return 10;
    if(strcmp(c,"Orompello")==0) return 11;
    if(strcmp(c,"Ongolmo")==0) return 12;
    if(strcmp(c,"Paicavi")==0) return 13;//hasta paicavi estan en paralelo
    if(strcmp(c,"Chacabuco")==0) return 14;
    if(strcmp(c,"Cochrane")==0) return 15;
    if(strcmp(c,"San Martin")==0) return 16;
    if(strcmp(c,"O'Higgins")==0) return 17;
    if(strcmp(c,"Barros Arana")==0) return 18;
    if(strcmp(c,"Freire")==0) return 19;
    if(strcmp(c,"Maipu")==0) return 20;
    if(strcmp(c,"Los Carrera")==0) return 21;
    if(strcmp(c,"Pedro Aguirre Cerda")==0) return 22;
}
// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[]){
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed distance
// array
void printSolution(int dist[], int final){
    printf("Distancia del origen es:\t\t al vertice\n");
    printf("%d \t\t\t\t %d\n", dist[final],final);
}
 
// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src, int final){
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
    printSolution(dist,final);
}
int main()
{
    int mat[23][23]={
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
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};//diagonal ;
    char *token;
    char str[100]; 
    fgets(str, sizeof(str), stdin);
    int i=0;
    token = strtok(str," ");
    char *c1,*c2,*c3,*c4;
    c1=token;
    while( token != NULL ) {
        token = strtok(NULL, " ");
        if(i==0){ c2=token;}
        if(i==1){ c3=token;}
        if(i==2){ c4=token;}
        i++;
    }
    dijkstra(mat, mat[to_int(c1)][(int)strtol(c2, NULL, 10)],to_int(c3));
    return 0;
}
