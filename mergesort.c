#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void merge(int sorted[], int start, int mid, int end)
{
    int m1 = mid - start + 1;
    int m2 = end - mid;

    int arr1[m1], arr2[m2];

    for (int i = 0; i < m1; i++)
        arr1[i] = sorted[start + i];
    for (int j = 0; j < m2; j++)
        arr2[j] = sorted[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    while (i < m1 && j < m2)
    {
        if (arr1[i] <= arr2[j])
        {
            sorted[k] = arr1[i];
            i++;
        }
        else
        {
            sorted[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < m1)
    {
        sorted[k] = arr1[i];
        i++;
        k++;
    }

    while (j < m2)
    {
        sorted[k] = arr2[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int start, int end)
{

    int middle = start + (end - start) / 2;

    mergesort(arr, start, middle);
    mergesort(arr, middle + 1, end);

    merge(arr, start, middle, end);
}

int main()
{
    printf("Shubhankar Nautiyal\nSap id - 1000014085\n\n");

    int n;

    printf("Enter no. of element to insert: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nBefore Sorting: ");
    printArray(arr, n);

    mergesort(arr, 0, n - 1);

    printf("\nAfter Sorting: ");
    printArray(arr, n);

    return 0;
}
