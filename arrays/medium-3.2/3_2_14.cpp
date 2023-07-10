// count subarrays with sum equal to k

#include <bits/stdc++.h>
using namespace std;

// brute/better of count subarray where sum = k
void countSubarray(int arr[], int n, int k)
{
    int count = 0;

    // checking for each element and its subarrays
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
                count++;
        }
    }

    cout << count;
}

// optimal
int countSubArr(int a[], int k, int n)
{
    // int n = sizeof(a) / sizeof(a[0]);

    // key is storing the prefix sum and value is the count of the prefix sum in the subarray
    unordered_map<int, int> preSumMap;
    int prefixSum = 0;
    int count = 0;

    // for cases where prefix sum == k
    preSumMap[0] = 1;

    for (int i = 0; i < n; i++)
    {
        // calculating the prefix sum i.e. x
        prefixSum += a[i];

        int rem = prefixSum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            count += preSumMap[rem];
        }

        preSumMap[prefixSum] += 1;
    }

    return count;
}

int main()
{
    int arr[] = {3, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Count of the subarrays with sum k: " << countSubArr(arr, 6, n);
    return 0;
}