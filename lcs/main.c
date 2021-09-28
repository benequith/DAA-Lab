#include <stdio.h>
#include <stdlib.h>
#include<string.h>


#define max(a,b) (((a)>(b))?(a):(b))
void printlcs(int C[][15],char* str1,int m,int n,char* lcs)
{
    int i=m;
    int j=n;

    while(C[i][j]>0)
    {
        if(C[i][j-1]==C[i][j])
        {
            if(C[i-1][j]==C[i][j])
            {
                printlcs(C,str1,i-1,j,lcs);
            }
            j--;
        }
        else if(C[i-1][j]==C[i][j])
        {
            if(C[i][j-1]==C[i][j])
                printlcs(C,str1,i,j-1,lcs);
            i--;
        }
        else
        {
            lcs[C[i][j]-1]=str1[i-1];
            i--;
            j--;
        }
    }
    printf("%s\n", lcs);
}



void lcs( char *str1, char *str2, int m, int n )
{
    int C[m+1][n+1],L[100];
    char lcs[30];
    int i,j,k,l;
    for (i=0; i<=m; i++)
    {
        for (j=0;j<=n;j++)
        {
            if (i==0||j==0)
                C[i][j]= 0;

            else if (str1[i-1] == str2[j-1])
                C[i][j]= C[i-1][j-1]+ 1;

            else
                C[i][j]= max(C[i-1][j],C[i][j-1]);
        }
}

    l= C[m][n];
    printf("The length of LCS is:%d",C[m][n]);
    printf("\nTable for LCS:\n");
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

    lcs[l]='\0';
    printf("\nAll possible subsequence:\n");
    printlcs(C,str1,m,n,lcs);


}


int main()
{

    int m,n;
    char str1[50],str2[50];
    printf("\nEnter the main string:");
    fgets(str1,50,stdin);
    printf("\nEnter the substring:");
    fgets(str2,50,stdin);
    m = strlen(str1)-1;
    n = strlen(str2)-1;
    lcs(str1,str2,m,n);
    return 0;
}
