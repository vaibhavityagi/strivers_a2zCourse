#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int item)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == item)
            return i;
    }
    return -1;
}

int linerSearchInRange(int arr[], int n, int item, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == item)
            return i;
    }
    return -1;
}

int main()
{
    // int n;
    // cout << "Enter the length of array: ";
    // cin >> n;
    // int arr[n];
    // cout << "Enter the elements of the array: ";
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];

    // int item;
    // cout << "Enter the item to be searched in array: ";
    // cin >> item;
    // int ans = linerSearchInRange(arr, n, item, 2, 5);
    // if (ans == -1)
    //     cout << " not found";
    // else
    //     cout << "found at " << ans;

    return 0;
}