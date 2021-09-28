#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void mergeSort(long int *arr , int l, int r);
void merge(long int *arr, int l, int m, int r);
void quick(long int *arr,long int low,long int high);
void insertionSort(long int *arr, int n);
long int *create(long int *arr,long int n);
void display(long int *arr, long int n);
void createdata(long int n);

int main()
{
    long int n;
    int ch;
    long int *arr;
    clock_t start, end;
    double time_taken;


    printf("\nEnter a number:");
    scanf("%ld",&n);
    createdata(n);
    printf("\nDataset created");
    arr = (long int*)malloc(n* sizeof(long int));
    printf("\nCreating array and reading from file");


    do{
            arr=create(arr,n);
            printf("\n1. Quick Sort\n2. Merge Sort\n3. Insertion Sort\n4. Heap Sort\n5. To change input size\n6. Exit\nEnter your choice:");
            scanf("%d",&ch);
            start = clock();
            switch(ch){


                case 1: quick(arr,0,n-1);
                        //display(arr,n);
                        break;

                case 2: mergeSort(arr,0,n- 1);
                        display(arr,n);
                        break;

                case 3: insertionSort(arr,n);
                        display(arr,n);
                        break;

                case 4:

                case 5: free(arr);
                        printf("\nEnter a number:");
                        scanf("%ld",&n);
                        arr = (long int*)malloc(n* sizeof(long int));
                        break;
                default: printf("\nWrong choice");
            }
            end= clock();
             time_taken= ((double)(end-start))/ (double)CLOCKS_PER_SEC;
            printf("\nTime taken by program block: %lf", time_taken);
        } while(ch!=7);





        return 0;
    }


void createdata(long int n){
     FILE *fp;
     long int r,t=0,i;
     long int *arr;
     arr= (long int*)malloc(100000*sizeof(long int));
     for(i=0;i<100000;i++){
        arr[i]=i;
     }

     srand( time(NULL) );

     for(i=100000;i>0;i--){
        r=rand()%100000;
        t=arr[i-1];
        arr[i-1]=arr[r];
        arr[r]=t;
     }
     fp=fopen("input.txt","w");
     for(i = 0; i <100000; ++i)
   {
      fprintf(fp,"%ld ",arr[i]);
   }

     fclose(fp);

}

long int *create(long int *arr, long int n){

    FILE *f;
    long int i;
    f= fopen("input.txt","r");
    if(f==NULL){
       printf("\nFile is empty");
    }
    else{
            for(i=0;i<n;i++){
            fscanf(f,"%ld",&arr[i]);
        }
    }
    fclose(f);
    //display(arr,n);
    return arr;

}

/* Sorting Algorithms*/
// QUICK SORT

long int partition(long int *arr,long int low, long int high){

    long int pivot,i,j,temp=0;
    pivot = arr[high];
    i=low-1;

    for (j=low;j<high;j++)
    {
        if (arr[j]<=pivot)
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return (i + 1);

}


void quick(long int *arr, long int low, long int high){
    if (low < high)
    {
        long int p= partition(arr,low,high);
        quick(arr,low,p-1);
        quick(arr,p+1,high);
    }
}


// MERGE SORT

void mergeSort(long int *arr, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void merge(long int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
    R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// INSERTION SORT

void insertionSort(long int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


//DISPLAY FUNCTION

void display(long int *arr, long int n){
    long int i;
    printf("\nThe array is:\n");
    for(i=0;i<n;i++)
        printf("%ld ",arr[i]);

    printf("\n");
}
