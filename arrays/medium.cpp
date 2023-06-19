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

vector<int> rearrangeBySign(int arr[], int n)
{
    vector<int> ans(n, 0);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
        else
        {
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }

    return ans;
}

// variety 2 of the rearrange by sing question but with unequal number of

// leaders in an array
// A Leader is an element that is greater than all of the elements on its right side in the array
vector<int> printLeadersBruteForce(int arr[], int n)
{

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        bool leader = true;

        // Checking whether arr[i] is greater than all
        // the elements in its right side
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[i])
            {

                // If any element found is greater than current leader
                // curr element is not the leader.
                leader = false;
                break;
            }

        // Push all the leaders in ans array.
        if (leader)
            ans.push_back(arr[i]);
    }

    return ans;
}

vector<int> leaders(int a[], int n)
{
    // I came up w this, this is almost the optimal soln, right logic, but to reduce the number of loops, we are looping from the back
    /*
    int maxi = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            maxi = max(maxi, a[j]);
        }

        if (a[i] > maxi)
            cout << a[i] << " ";

        maxi = INT_MIN;
    }
    //since last element is always a leader
    cout << a[n - 1];
    */

    // optimal solution
    vector<int> ans;

    ans.push_back(a[n - 1]);

    int maxi = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > maxi)
        {
            maxi = a[i];
            ans.push_back(a[i]);
        }
    }

    return ans;
}

// better approach
void setZeros(int arr[3][4], int r, int c)
{
    // initializing row and column arrays as zero
    int row[r] = {0};
    int col[c] = {0};

    // finding the row and column at which zero is present
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // updating the array
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (row[i] == 1 || col[j] == 1)
                arr[i][j] = 0;
        }
    }

    // printing the updated matrix
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// optimal approach
void setZerosOpt(int mat[3][3], int r, int c)
{
    // initializing row and column arrays as zero
    // int row[r] = {0}; -> mat[..][o]
    // int col[c] = {0}; -> mat[0][..] + col variable

    int col0 = 1;

    // step 1 -> traversing the array and marking for the rows and cols which has to be converted to 0
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 0)
            {
                // marking i-th row
                mat[i][0] = 0;

                // marking j-th col
                if (j != 0)
                    mat[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // step 2 -> mark all the rows and cols 0 except the first row and first col
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            // no need to mark the ele which is already zero
            if (mat[i][j] != 0)
            {
                if (mat[i][0] == 0 || mat[0][j] == 0)
                    mat[i][j] = 0;
            }
        }
    }

    // step 3 -> mark the 1st col then the 1st row
    if (mat[0][0] == 0)
    {
        for (int j = 0; j < c; j++)
        {
            mat[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < r; i++)
        {
            mat[i][0] = 0;
        }
    }

    // printing the updated matrix
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// brute/better and optimal
vector<vector<int>> matrixRotate(vector<vector<int>> &mat, int r)
{
    // approach - transpose the matrix and then reverse the transposed matrix
    // this is what I conjured up
    /*
    //  temp matrix to store the transpose of mat
    vector<vector<int>> temp(r, vector<int>(r, 0));

    // transpose of mat into temp
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            temp[i][j] = mat[j][i];
        }
    }

    // reverse storing the values of temp into mat
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            mat[i][j] = temp[i][2 - j];
        }
    }
    */

    // optimal
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < r; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }

    return mat;
}

// brute of printing a matrix in spiral manner
vector<vector<int>> spiral(vector<vector<int>> &mat, int r, int c)
{
    // first row
    for (int i = 0; i <= 0; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mat[i][j] << " ";
        }
    }

    // outer most col
    for (int i = 1; i < r; i++)
    {
        for (int j = c - 1; j <= c - 1; j++)
        {
            cout << mat[i][j] << " ";
        }
    }

    // bottom most row
    for (int i = r - 1; i <= r - 1; i++)
    {
        for (int j = c - 2; j >= 0; j--)
        {
            cout << mat[i][j] << " ";
        }
    }

    // outermost col
    for (int i = r - 2; i > 0; i--)
    {
        for (int j = c - c; j <= 0; j++)
        {
            cout << mat[i][j] << " ";
        }
    }
}

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
int countSubArr(int nums[], int k)
{
    int n = sizeof(nums) / sizeof(int);
}

int main()
{
    int arr[] = {1, 1, 1};
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

    // vector<int> ans = rearrangeBySign(arr, n);
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";

    // vector<int> ans = leaders(arr, n);
    // for (int it : ans)
    //     cout << it << " ";

    // int matrix2[3][4] = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    // int matrix1[3][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    // setZerosOpt(matrix1, 3, 3);

    // vector<vector<int>> matrix3 = {{1, 2, 3},
    //                                {4, 5, 6},
    //                                {7, 8, 9}};

    // vector<vector<int>> ans = matrixRotate(matrix3, 3);
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // vector<vector<int>> matrix4 = {{1, 2, 3},
    //                                {4, 5, 6},
    //                                {7, 8, 9}};

    // spiral(matrix4, 3, 3);

    // countSubarray(arr, n, 2);

    cout << countSubArr(arr, 2);

    return 0;
}