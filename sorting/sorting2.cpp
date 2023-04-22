#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int left = low;    // starting pointer of the left half
    int rgt = mid + 1; // starting pointer of the right half

    while ((left <= mid) && (rgt <= high))
    {
        if (arr[left] < arr[rgt])
        {
            temp.emplace_back(arr[left]);
            left++;
        }

        else
        {
            temp.emplace_back(arr[rgt]);
            rgt++;
        }
    }

    while (left <= mid)
    {
        temp.emplace_back(arr[left]);
        left++;
    }

    while (rgt <= high)
    {
        temp.emplace_back(arr[rgt]);
        rgt++;
    }

    // transferring from temp to the actual array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
};

void mergeSort(int arr[], int low, int high)
{
    // base condition
    if (low == high)
        return;

    int mid = (low + high) / 2;

    // left half
    mergeSort(arr, low, mid);
    // right half
    mergeSort(arr, mid + 1, high);
    // merging the two halves
    merge(arr, low, mid, high);
};

int partition(int arr[], int low, int high)
{
    int count = 0;
    int piv = arr[low];
    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] <= piv)
            count++;
    }

    int pivIndex = low + count;

    int temp1 = arr[low];
    arr[low] = arr[pivIndex];
    arr[pivIndex] = temp1;

    // taking two pointers, i at the start of the array and j at the end of the array
    int i = low;
    int j = high;
    while (i < pivIndex && j > pivIndex)
    {
        while (arr[i] < piv)
            i++;

        while (arr[j] > piv)
            j--;

        if (i < pivIndex && j > pivIndex)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return pivIndex;
}

void quickSort(int arr[], int low, int high)
{

    // base condition
    if (low >= high)
        return;

    int pivloc = partition(arr, low, high);

    // left sublist sorting
    quickSort(arr, low, pivloc - 1);

    // right sublist sorting
    quickSort(arr, pivloc + 1, high);
}

int main()
{
    // int n;
    // cout << "Enter the number of elements: ";
    // cin >> n;
    // int arr[n];
    // cout << "Enter the elements of the array: ";
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];

    // quickSort(arr, 0, n - 1);

    // // printing the final sorted array
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";

    char arr[30];
    gets(arr);
    puts(arr);

    return 0;
}

// normal code/algo for merging
/*
    int arr1[5] = {5, 8, 9, 28, 34};
    int arr2[7] = {4, 22, 25, 30, 33, 40, 42};
    int arr3[12];

    int i = 0;
    int j = 0;
    int k = 0;

    //storing elements in the temp arr in sorted array
    //condition becomes false the moment any one of the two arrays is over
    while ((i <= 5) && (j <= 7))
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    //adding the remaining elements to the temp array
    while (i <= 5)
        arr3[k++] = arr1[i++];
    while (j <= 7)
        arr3[k++] = arr2[i++];

    for (int l = 0; l < 12; l++)
        cout << arr3[l] << " ";
    */