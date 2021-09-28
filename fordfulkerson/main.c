#include <stdio.h>

#define min(a,b) (((a)<(b))?(a):(b))

#define A 0
#define B 1
#define C 2
#define MAX_NODES 1000
#define O 999999999

int n;
int e;
int capacity[MAX_NODES][MAX_NODES];
int flow[MAX_NODES][MAX_NODES];
int color[MAX_NODES];
int pred[MAX_NODES];


int head, tail;
int q[MAX_NODES + 2];

void enqueue(int x) {
  q[tail] = x;
  tail++;
  color[x] = B;
}

int dequeue() {
  int x = q[head];
  head++;
  color[x] = C;
  return x;
}

int bfs(int start, int target) {
  int u, v;
  for (u = 0; u < n; u++) {
    color[u] = A;
  }
  head = tail = 0;
  enqueue(start);
  pred[start] = -1;
  while (head != tail) {
    u = dequeue();
    for (v = 0; v < n; v++) {
      if (color[v] == A && capacity[u][v] - flow[u][v] > 0) {
        enqueue(v);
        pred[v] = u;
      }
    }
  }
  return color[target] == C;
}


int fordFulkerson(int src, int dest) {
  int i, j, k;
  int max_flow = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      flow[i][j] = 0;
    }
  }

  while (bfs(src, dest)) {
    int increment = O;
    for (k=n - 1; pred[k] >= 0; k = pred[k]) {
      increment = min(increment, capacity[pred[k]][k] - flow[pred[k]][k]);
    }
    for (k = n - 1; pred[k] >= 0; k = pred[k]) {
      flow[pred[k]][k] += increment;
      flow[k][pred[k]] -= increment;
    }
    max_flow += increment;
  }
  return max_flow;
}

int main() {
    int s, t,weight,i,src,dest;
    printf("\nEnter the number of vertices and edges:");
    scanf("%d %d",&n,&e);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      capacity[i][j] = 0;
    }
  }

  for(i=0;i<e;i++){
    printf("\nEnter the source node and the destination node and weight for edge %d:",i+1);
    scanf("%d %d %d",&src,&dest,&weight);
    capacity[src][dest]= weight;
  }
    printf("\nEnter the source and sink:");
    scanf("%d %d",&s,&t);
  printf("\nMax Flow of the Network: %d", fordFulkerson(s, t));
}
