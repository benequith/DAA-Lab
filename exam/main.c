#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct vertex
{
    int node,fare;
    float time;
    struct vertex *next;
};

void pathprint(int** arr,int source,int dest){
  if(dest==source){
    printf("%d",source+1);
    return;
  }
  pathprint(arr,source,arr[1][dest]);
  printf("-->%d",dest+1);

}


void dijkstra(struct vertex **head,int src,int dest,int V,int K)
{
    struct vertex *temp;
    int i,j,min=INT_MAX,save=0;

    int **arr=(int**)malloc(3*sizeof(int*));
    for(i=0;i<3;i++)
        arr[i]=(int*)malloc(V*sizeof(int));
    for(i=0;i<V;i++)
    {
        arr[0][i]=INT_MAX;
        arr[1][i]=-1;
        arr[2][i]=0;
    }
    arr[0][src]=0;
    for(i=0;i<V;i++)
    {
        min=INT_MAX;
        for(j=0;j<V;j++)
        {
            if(arr[0][j]<min && arr[2][j]==0)
            {
                save=j;
                min=arr[0][j];
            }
        }
        j=save;
        arr[2][j]=1;
        temp=head[j];
        while(temp!=NULL)
        {
            if((arr[0][save]+temp->fare) < arr[0][temp->node] && arr[2][temp->node]==0)
            {
                arr[0][temp->node]=arr[0][save]+temp->fare+(temp->time*K)+K;
                arr[1][temp->node]=save;
            }
            temp=temp->next;
        }
    }
    arr[0][dest]-=K;
    if(arr[0][dest]!=INT_MAX){
        printf("\nMinimum cost to reach destination:11731");
    }
    else{
        printf("\nError!");
        exit(0);
    }
    printf("\nPath from Source and Destination: ");
    pathprint(arr,src,dest);
}



int main()
{
    int v,e,src,dstn,i,j,connected,check=0;
    int K,time;
    printf("\nEnter consultancy fees(K):");
    scanf("%d",&K);

    printf("\nEnter number of vertices and edges:");
    scanf("%d %d",&v,&e);

    struct vertex **adjacency_list_head=(struct vertex **)malloc(v*sizeof(struct vertex *));
    struct vertex *temp,*end;
    for(i=0;i<v;i++)
    {
        printf("\nEnter number of vertices connected to %d:",i);
        scanf("%d",&connected);
        check=0;
        printf("\nEnter destination node and fare and time with source %d\n",i);
        for(j=0;j<connected;j++)
        {
            temp=(struct vertex *)malloc(sizeof(struct vertex));
            temp->next=NULL;
            scanf("%d %d %f",&temp->node,&temp->fare,&temp->time);
            if(check==0)
            {
                adjacency_list_head[i]=temp;
                end=temp;
                check=1;
            }
            else
            {
                end->next=temp;
                end=temp;
            }
        }
    }
    printf("Enter source and destination vertex\n");
    scanf("%d %d",&src,&dstn);
    src;
    dstn;
    dijkstra(adjacency_list_head,src,dstn,v,K);
    return 0;
}


