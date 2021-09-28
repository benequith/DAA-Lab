#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define INF INT_MAX
int V=4;

void floyd_warshall(int graph[4][4])
{
	int dist[4][4];
	int path[4][4];
	int i,j,k,src,dst;

	//Assign all values of graph to allPairs_SP
	for(i=0;i<V;++i)
		for(j=0;j<V;++j)
        {
            dist[i][j] = graph[i][j];
            path[i][j] = -1;
        }


	//Find all pairs shortest path by trying all possible paths
	for(k=0;k<V;++k){	//Try all intermediate nodes
		for(i=0;i<V;++i){	//Try for all possible starting position
			for(j=0;j<V;++j)	//Try for all possible ending position
			{
				if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)	//SKIP if K is unreachable from i or j is unreachable from k
					continue;
				else if(dist[i][k]+dist[k][j] < dist[i][j])     //Check if new distance is shorter via vertex K
				{
				    dist[i][j] = dist[i][k] + dist[k][j];
				    path[i][j] = k;
				}
			}
		}
	}


	//Check for negative edge weight cycle
	for(int i=0;i<V;++i)
		if(dist[i][i] < 0)
		{
			printf("Negative edge weight cycle is present\n");
			return;
		}

	//Print Shortest Path Graph
	//(Values printed as INT_MAX defines there is no path)
	for(i=0;i<V;++i)
	{
		for(j=0;j<V;++j)
            if(dist[i][j]!=INT_MAX)
                printf("%d to %d distance is %d\n",i,j,dist[i][j]);
		printf("=================================\n");
	}

    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            printf("%d ",path[i][j]);
        }
        printf("\n");
    }
    printf("enter source and destination \n");
	scanf("%d %d",&i,&j);
    printf("\n%d <-",j);
    while(path[i][j]!=-1)
    {
        printf("%d <-",path[i][j]);
        j=path[i][j];
    }
    printf(" %d \n",i);
}

int main()
{
	/*int graph[6][6] = { {0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
						{INT_MAX, 0, 4, 2, 7, INT_MAX},
						{INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
						{INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
						{INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
						{INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0} };
    */
    /*int graph[4][4] ={  { 0, 3, INT_MAX, 7 },
                        { 8, 0, 2, INT_MAX },
                        { 5, INT_MAX, 0, 1 },
                        { 2, INT_MAX, INT_MAX, 0 } };
    */
    int graph[4][4] = {{0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}};


	floyd_warshall(graph);
	return 0;
}

//TIME COMPLEXITY: O(V^3)
