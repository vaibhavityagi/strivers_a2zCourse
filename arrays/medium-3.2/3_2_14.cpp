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
int countSubArr(int a[], int k)
{
    int n = sizeof(a) / sizeof(int);
    // key is storing the prefix sum and value is the index
    unordered_map<int, int> preSumMap;
    int prefixSum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        // calculating the prefix sum i.e. x
        prefixSum += a[i];

        if (prefixSum == k)
            maxLen = max(maxLen, i + 1);

        // calculating x-k, if it is present in the map then we check if it is the maxLen or not
        int rem = prefixSum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // if the prefix sum is not present in the map, we add it
        // if condition added for cases like {2, 0, 0, 0, 3}, k = 3
        if (preSumMap.find(prefixSum) == preSumMap.end())
            preSumMap[prefixSum] = i;
    }
}

int main()
{
    int arr[] = {1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    countSubarray(arr, n, 2);
    return 0;
}