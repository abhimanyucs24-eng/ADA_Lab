#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    srand(time(NULL));

    for(int size = 10000; size <= 50000; size += 10000)
    {
        int arr[size];

        for(int i = 0; i < size; i++)
        {
            arr[i] = rand() % 50000;
        }

        clock_t start, end;

        start = clock();

        quickSort(arr, 0, size - 1);

        end = clock();

        double Time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Input Size: %d\n", size);
        printf("Start Time: %ld\n", start);
        printf("End Time: %ld\n", end);
        printf("Execution Time: %f seconds\n\n", Time_taken);
    }

    return 0;
}