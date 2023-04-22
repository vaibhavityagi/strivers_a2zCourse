#include <bits/stdc++.h>
using namespace std;

// TC = O(N^2)
string twoSumBF(int a[], int n, int t)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == t)
            {
                return "YES!";
            }
        }
    }
    return "NO!";
}

// optimized, using map hashing
// key is the element of the array and value is the index of that element
//  2 + x = 14 --> x(moreNeeded) = 14-2
string twoSum(vector<int> arr, int n, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end())
            return "YES!";
        mpp[num] = i;
    }
    return "NO!";
}

// a tiny bit more optimized
//  TC = O(N) + O(NlogN) {one loop + sorting}
/*
string twoSum(vector<int> a, int n, int t)
{
    // sorts the array
    sort(a.begin(), a.end());

    // right and left pointers
    int left = 0, right = n - 1;

    // will run till the pointers dont cross each other
    while (right < left)
    {
        int sum = a[left] + a[right];
        if (sum == t)
            return "YES!";
        else if (sum < t)
            left++;
        else
            right++;
    }
    return "NO!";
}
*/

// brute force
void zero12(vector<int> &arr, int n)
{
    int zeroC = 0, oneC = 0, twoC = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zeroC++;
        else if (arr[i] == 1)
            oneC++;
        else
            twoC++;
    }

    // replacing the values in the original array
    for (int i = 0; i < zeroC; i++)
        arr[i] = 0;
    for (int i = zeroC; i < oneC + zeroC; i++)
        arr[i] = 1;
    for (int i = oneC + zeroC; i < n; i++)
        arr[i] = 2;
}

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int target = 14;
    // cout << twoSum(arr, 4, target);
    zero12(arr, 6);
    for (auto it : arr)
        cout << it << " ";
    return 0;
}