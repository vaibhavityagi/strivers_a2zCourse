#include <bits/stdc++.h>
using namespace std;

int minIndex(int arr[], int n)
{
    // setting the index of 0th element at the min number
    int min = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[min])
            min = i;
    }

    return min;
}

// not passing the test case where all the elements are same and second hightest doesnt exist
int print2largest(int arr[], int n)
{
    if (n == 0 || n == 1)
        return -1;

    int max;
    for (int i = 0; i < 2; i++)
    {
        max = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > max)
            {
                if (i > 0)
                {
                    if (arr[j] > max && arr[0] != arr[j])
                    {
                        max = arr[j];
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
                else
                {
                    max = arr[j];
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    return max;
}

int secondLargest(int arr[], int n)
{
    // if the array is empty or has only two elements
    if (n < 2)
        return -1;

    // if all the elements in the array are same
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            count++;
    }
    if (count >= n - 1)
        return -1;

    // finding the second largest
    int large = INT_MIN;
    int secondLarge = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > large)
        {
            secondLarge = large;
            large = arr[i];
        }
        else if (arr[i] > secondLarge && arr[i] != large)
            secondLarge = arr[i];
    }

    return secondLarge;
}

int secondSmallest(int arr[], int n)
{
    // if the array is empty or has only two elements
    if (n < 2)
        return -1;

    // if all the elements in the array are same
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            count++;
    }
    if (count >= n - 1)
        return -1;

    // finding the second smallest
    int small = INT_MAX;
    int secondSmall = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < small)
        {
            secondSmall = small;
            small = arr[i];
        }
        else if (arr[i] < secondSmall && arr[i] != small)
            secondSmall = arr[i];
    }

    return secondSmall;
}

bool arraySortedOrNot(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }

    return true;
}

// tc = O(NlogN) + O(N){for inserting the elements into the set + for iterating over the set and replacing the elements in the actual array}
// sc = O(N);
int remove_duplicate_bf(int a[], int n)
{
    set<int> hash;

    for (int i = 0; i < n; i++)
        hash.insert(a[i]);

    int i = 0;
    for (auto it : hash)
        a[i++] = it;

    return hash.size();
}

// optimized two pointer approach
// tc = O(N); sc = O(1)
int remove_duplicate_opt(int a[], int n)
{
    // check if the array contains any element or not
    if (n == 0)
        return 0;

    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (a[i] != a[j])
        {
            i++;
            a[i] = a[j];
        }
    }

    return i + 1;
}

void rotateLeft(int a[], int n)
{
    /*
    //my approach
    for (int i = 0; i < n - 1; i++)
    {
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
    }
    */

    // optimized best approach
    int temp = a[0];
    for (int i = 0; i < n - 1; i++)
        a[i] = a[i + 1];

    a[n - 1] = temp;

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

// brute force, was able to come up with this myself based on rotation by one place
void rotateLeftB(int a[], int n, int k)
{
    // checking for various base conditions
    if (n == 0)
        return;
    if (k > n)
        return;

    // int temp[k] could also be used
    vector<int> temp;

    // taking the values to be moved towards the end in a temp array
    for (int i = 0; i < k; i++)
    {
        temp.push_back(a[i]);
    }

    // left rotating the rest of the values
    for (int i = 0; i < n - k; i++)
        a[i] = a[i + k];

    // placing the values in the temp array at the last of the rotated values
    for (int i = 0; i < k; i++)
        a[i + n - k] = temp[i];

    // printing the rotated array
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

// optimized solution
void reverse(int a[], int start, int end)
{
    while (start <= end)
    {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}
void rotateLeftK(int arr[], int n, int k)
{
    // reverse 0 to k-1 elements
    reverse(arr, 0, k - 1);

    // reverse the remaining array i.e k to n-1
    reverse(arr, k, n - 1);

    // reverse the entire array
    reverse(arr, 0, n - 1);
}

void pushZerosToEnd(int arr[], int n)
{
    // finding the first index of zero
    int k = 0;
    while (k < n)
    {
        if (arr[k] == 0)
            break;
        else
            k++;
    }

    // i is at the index of 0th element and j is at the next element
    // if j != 0, then swap the 0th element at i with j
    // else increment j till we find the immediate non-zero element
    int i = k;
    int j = k + 1;
    while (i < n && j < n)
    {
        if (arr[j] != 0)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }

        j++;
    }
}

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> temp;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (temp.size() == 0 || temp.back() != arr1[i])
                temp.push_back(arr1[i]);
            i++;
        }

        else
        {
            if (temp.size() == 0 || temp.back() != arr2[j])
                temp.push_back(arr2[j]);
            j++;
        }
    }

    // adding the remaining elements in the temp vector
    while (i < n)
    {
        if (temp.back() != arr1[i])
            temp.push_back(arr1[i]);
        i++;
    }

    while (j < m)
    {
        if (temp.back() != arr2[j])
            temp.push_back(arr2[j]);
        j++;
    }

    return temp;
}

vector<int> findIntersection(int arr1[], int arr2[], int n, int m)
{
    vector<int> intersect;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
            i++;

        else if (arr1[i] > arr2[j])
            j++;

        else
        {
            intersect.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return intersect;
}

// missing number

// bruteBetter -> TC:O(N) + O(N) = O(2N); SC: O(N)
void missingNumber(int a[], int n)
{
    int hash[n + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }

    int twice = 0, missing = 0;
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
            twice = i;
        else if (hash[i] == 0)
            missing = i;
    }

    cout << twice << " " << missing;
}

// optimized missing number -> TC: O(N); SC: O(N)
void missingNumberOpt1(int a[], int n)
{
    int sum = (n * (n + 1)) / 2;
    int sumArr = 0;
    for (int i = 0; i < n - 1; i++)
        sumArr = sumArr + a[i];

    cout << "Missing number: " << sum - sumArr << endl;
}

// most optimized [XOR approach] -> TC: O(N)
void missingNumberOpt2(int a[], int n)
{
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ n;

    cout << "Missing number: " << (xor1 ^ xor2) << endl;
}

// returning the most number of consecutive ones
int consecOnes(int arr[], int n)
{
    int maxi = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            // if (count > max)
            //     max = count;
            maxi = max(maxi, count);
        }
        else
            count = 0;
    }

    return maxi;
}

// brute force -> TC: O(N2); SC: O(1)
int singleNumberBF(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; i < n; j++)
        {
            if (arr[j] == arr[i])
                count++;
        }

        if (count == 1)
            return arr[i];
    }
}

// brute better using hashing

// optimized using XOR
int singleNumberOpt(int arr[], int n)
{
    int xor1 = 0;
    for (int i = 0; i < n; i++)
        xor1 = xor1 ^ arr[i];

    return xor1;
}

void longestSubArrKBF(int a[], int k, int n)
{
    /*

    ----- this approach doesnt pass all the test cases as it is only moving forward
            fails in cases like {10, 5, 2, 7, 1, 9}, k = 15

    int sum = 0, count = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum == k)
        {
            sum = 0;
            count = 0;
        }
        if (sum < k)
        {
            sum = sum + a[i];
            count++;
            maxi = max(count, maxi);
        }
    }

    cout << maxi;
    */

    // brute force approach - this is taking one element and adding the sum of all the other elements in the subarray
    // TC = O(n2)
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }

    cout << len;
}

// using hashing, this is the optimal approach if the array contains both positive and negative numbers
void longestSubArrK(int a[], int k, int n)
{
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

    cout << "Maximum lenght of the subarray having sum " << k << ": " << maxLen;
}

// TC = O(2N)
void longestSubArrKOpt(int a[], int k, int n)
{
    int maxLen = 0;
    int sum = 0;
    int right = 0, left = 0;
    while (right < n)
    {
        sum += a[right];

        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
    }

    cout << maxLen;
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

    // int min = minIndex(arr, n);
    // cout << "Minimum element is " << arr[min];

    // int arr[] = {15, 12, 0, 1, 0, 2, 2, 19};
    // int k = remove_duplicate_bf(arr, 9);
    // for (int i = 0; i < k; i++)
    //     cout << arr[i] << " ";

    // pushZerosToEnd(arr, 8);
    // for (int i = 0; i < 8; i++)
    //     cout << arr[i] << " ";

    // int arr1[] = {1, 2, 3, 3, 4, 5, 6, 7};
    // int arr2[] = {3, 3, 4, 4, 5, 8};
    // vector<int> ans = findIntersection(arr1, arr2, 8, 6);
    // for (auto it : ans)
    //     cout << it << " ";

    int array[] = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    int n = sizeof(array) / sizeof(array[0]);
    longestSubArrKOpt(array, 6, 5);
    return 0;
}
