#include <stdio.h>
#include <stdlib.h>

#define INFINITY 99999

struct Edge {
  int u,v,w;
};

struct Graph {
  int V,E;
  struct Edge *edge;
};

void bellmanford(struct Graph *g, int source,int dest);
void display(int arr[], int size);

void printPath(int parent[],int source, int dest)
{
  if(source==dest){
    printf("%d",source);
    return;
  }
  printPath(parent,source,parent[dest]);
  printf("-->%d",dest);
}


int main(void) {
  int src,dest;
  struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
  printf("\nEnter the number of Vertices and Edges:");
  scanf("%d %d",&g->V,&g->E);
  g->edge =(struct Edge *)malloc(g->E * sizeof(struct Edge));
    for(int i=0;i<g->E;i++){
        printf("Enter the source and destination nodes and weight of edge %d:",i+1);
        scanf("%d %d %d",&g->edge[i].u,&g->edge[i].v,&g->edge[i].w );
    }
  printf("\nEnter the source and destination:");
  scanf("%d %d",&src,&dest);
  bellmanford(g,src,dest);
  return 0;
}

void bellmanford(struct Graph *g, int source,int dest) {
  int i, j, u, v, w;
  int tV = g->V;
  int tE = g->E;
  int d[tV];
  int p[tV];

  for (i = 0; i < tV; i++) {
    d[i] = INFINITY;
    p[i] = 0;
  }

  d[source] = 0;
  p[source]= -1;

  for (i = 1; i <= tV - 1; i++) {
    for (j = 0; j < tE; j++) {
      u = g->edge[j].u;
      v = g->edge[j].v;
      w = g->edge[j].w;

      if (d[u] != INFINITY && d[v] > d[u] + w) {
        d[v] = d[u] + w;
        p[v] = u;
      }
    }
  }

  for (i = 0; i < tE; i++) {
    u = g->edge[i].u;
    v = g->edge[i].v;
    w = g->edge[i].w;
    if (d[u] != INFINITY && d[v] > d[u] + w) {
      printf("Negative weight cycle detected!\n");
      return;
    }
  }
  printf("Distance array: ");
  display(d, tV);
  printf("Predecessor array: ");
  display(p, tV);
  printPath(p,source,dest);
}

void display(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
