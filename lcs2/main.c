#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printDP(int **arr,char* ar1,int l1,int l2,char* arl1);


int main()
{
    int l1,l2,i,j,check=0;
    char ar1[50],ar2[50];
    printf("\nEnter the main string:");
    scanf("%s",&ar1);
    printf("\nEnter the substring:");
    scanf("%s",&ar2);
    l1=strlen(ar1);
    l2=strlen(ar2);

    //CREATING DP TABLE
    int **arr=(int **)malloc((l1+1)*sizeof(int *));
    for(i=0;i<=l1;i++)
        arr[i]=(int *)malloc((l2+1)*sizeof(int *));

    //PREPROCESSING DP TABLE
    for(i=0;i<=l1;i++)
        arr[i][0]=0;
    for(i=0;i<=l2;i++)
        arr[0][i]=0;

    //DP ITERATION STARTS
    for(i=1;i<=l1;i++)
    {
        for(j=1;j<=l2;j++)
        {
            if(ar1[i-1]==ar2[j-1])
                arr[i][j]=arr[i-1][j-1]+1;
            else
            {
                if(arr[i-1][j]>arr[i][j-1])
                    arr[i][j]=arr[i-1][j];
                else
                    arr[i][j]=arr[i][j-1];
            }
        }
    }

    //PRINTING DP TABLE

    for(i=0;i<=l1;i++)
    {
        if(i!=0)
            printf("%c ",ar1[i-1]);
        for(j=0;j<=l2;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }

    //FINDING LCS from DP TABLE
    char arl1[arr[l1][l2]];
    i=l1;
    j=l2;
    printf(" ---------------- < LCS > -------------------- \n");
    printf("Length of LCS - %d\n\n", arr[l1][l2]);
    printf("Longest Common Subsequence \n");
    printDP(arr,ar1,l1,l2,arl1);
    return 0;
}

void printDP(int **arr,char* ar1,int l1,int l2,char* arl1)
{
    int i=l1;
    int j=l2;
    while(arr[i][j]>0)
    {
        if(arr[i][j-1]==arr[i][j])
        {
            if(arr[i-1][j]==arr[i][j])
            {
                printDP(arr,ar1,i-1,j,arl1);
            }
            j--;
        }
        else if(arr[i-1][j]==arr[i][j])
        {
            if(arr[i][j-1]==arr[i][j])
                printDP(arr,ar1,i,j-1,arl1);
            i--;
        }
        else
        {
            arl1[arr[i][j]-1]=ar1[i-1];
            i--;
            j--;
        }
    }
    printf("LCS - %s\n", arl1);
}
