#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        // finding the min index
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }

        // condition makes sure that there is no swapping if i is already the min element
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    // printing the array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
};

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int changes = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                changes++;
            }
        }

        // if there are no swaps ie the array is sorted
        if (changes == 0)
            break;
    }

    // printing the array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
};

// striver
void insertionSort1(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    // printing the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
};

// data structures through c in depth
// void insertionSort2(int arr[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         int k = arr[i];
//         for (int j = i - 1; j >= 0 && k < arr[j]; j--)
//             arr[j + 1] = arr[j];
//         arr[j + 1] = k;
//     }

//     // printing the sorted array
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
// };

int main()
{
    int len;
    cout << "Enter the length of the array: ";
    cin >> len;
    int arr[len];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    // selectionSort(arr, len);
    // bubbleSort(arr, len);
    insertionSort1(arr, len);
    return 0;
}