#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
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

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    srand(time(NULL));

    for(int size=10000; size<=50000; size+=10000){
        int arr[size];

        for(int i=0; i<size; i++){
            arr[i] = rand() % 50000;
        }

        clock_t start, end;

        start = clock();

        mergeSort(arr, 0, size-1);

        end = clock();

        double Time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Input Size: %d\n", size);
        printf("Start Time: %ld\n", start);
        printf("End Time: %ld\n", end);
        printf("Execution Time: %f seconds\n\n", Time_taken);
    }
    return 0;
}