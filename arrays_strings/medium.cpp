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

// optimal approach - dutch national flag algorithm or 3-pointer approach
void zero12Opt(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
            mid++;
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// using hash map
int majorityEleBF(int a[], int n)
{
    // key is the element, value is the frequency of the element
    map<int, int> mpp;

    // inserting the elements and their occurences into the map
    for (int i = 0; i < n; i++)
    {
        mpp[a[i]]++;
    }

    // iterating over the map to find which key has the highest value
    for (auto it : mpp)
    {
        if (it.second > (n / 2))
            return it.first;
    }

    return -1;
}

int majorityEleOpt(int a[], int n)
{
    int count = 0;
    int ele;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            ele = a[i];
            count = 1;
        }
        else if (ele == a[i])
            count++;
        else
            count--;
    }

    // checking if the ele is the majority element
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ele)
            count2++;
    }

    if (count2 > (n / 2))
        return ele;
    return -1;
}

// brute-better approach, TC = O(N2)
void maxSubArraySum(int a[], int n)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            maxSum = max(sum, maxSum);
        }
    }

    cout << "Maximum sum of a subarray: " << maxSum;
}

// optimal: Kadane's algorithm
void maxSubArraySumOpt(int a[], int n)
{
    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];

        if (sum > maxSum)
            maxSum = sum;

        if (sum < 0)
            sum = 0;
    }

    // this check is to ensure for the case of empty subarray
    //  if (maxSum < 0)
    //      maxSum = 0;

    cout << "Maximum sum of a subarray: " << maxSum;
}

void profit(int p[], int n)
{
    int mini = 0;
    int maxi = mini + 1;
    int profit = 0;

    // loop to find the day to buy on
    for (int i = 0; i < n; i++)
    {
        if (p[i] < p[mini])
            mini = i;
    }

    // loop to find the day to sell on
    for (int j = mini + 1; j < n; j++)
    {
        if (p[j] > p[maxi])
            maxi = j;
    }

    profit = p[maxi] - p[mini];
    cout << profit << endl;
}

void buyAndSell(int p[], int n)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, p[i]);
        maxProfit = max(maxProfit, p[i] - minPrice);
    }

    cout << "Maximum profit made: " << maxProfit << endl;
}

void rearrangeBySignBF(int arr[], int n)
{
    vector<int> positives;
    vector<int> negatives;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            positives.push_back(arr[i]);
        else
            negatives.push_back(arr[i]);
    }

    for (int i = 0; i < n - 1; i = i + 2)
    {
        arr[i] = positives[i / 2];
        arr[i + 1] = negatives[i / 2];
    }
}

int main()
{
    int arr[] = {1, 2, -3, -1, -2, 3};
    // int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int target = 14;
    // cout << twoSum(arr, 4, target);
    // zero12Opt(arr, 6);
    // for (auto it : arr)
    //     cout << it << " ";

    // cout << "Majority element : " << majorityEleOpt(arr, n);

    // maxSubArraySumOpt(arr, n);

    // buyAndSell(prices, n);

    rearrangeBySignBF(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}