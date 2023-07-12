// length of the longest subarray with sum = 0

#include <bits/stdc++.h>
using namespace std;

// brute - finding all the subarrays that exist
int brute(vector<int> &arr)
{
    int n = arr.size();
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int k = i; k < n; k++)
        {
            sum += arr[k];
            if (sum == 0)
            {
                len = max(len, k + 1 - i);
            }
        }
    }

    return len;
}

// optimal - using prefix sum
int longestSubArrWithSumZero(vector<int> &a)
{
    int n = a.size();
    unordered_map<int, int> mpp; // key = prefixSum; value = index
    int prefixSum = 0;
    int len = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum += a[i];

        if (prefixSum == 0)
            len = max(len, i + 1);

        else if (mpp.find(prefixSum) != mpp.end())
        {
            len = max(len, i - mpp[prefixSum]);
        }
        else
            mpp[prefixSum] = i;
    }

    return len;
}

int main()
{
    vector<int> array = {19, 0, 32, 49, 21, 25, 23, 31, 20, 5, 50, 49, 9, 44, 10, 13, 3, 31, 48, 22, -1};
    cout << longestSubArrWithSumZero(array);
    return 0;
}

// 21
// 19 0 32 49 21 25 23 31 20 5 50 49 9 44 10 13 3 31 48 22 -1
