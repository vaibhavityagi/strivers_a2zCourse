// count the number of subarrays with given xor k

#include <bits/stdc++.h>
using namespace std;

// brute - generate all the possible subarrays
int brute(vector<int> &a, int k)
{
    int n = a.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int xorr = 0;
        for (int j = i; j < n; j++)
        {
            xorr = xorr ^ a[j];
            if (xorr == k)
            {
                count++;
            }
        }
    }

    return count;
}

// optimal - using prefixXor
int optimal(vector<int> &a, int k)
{
    int n = a.size();

    unordered_map<int, int> mpp; // key = prefixXor, value = count
    mpp[0] = 1;                  // for cases when prefixXor = k, x = k^k = 0; and count increases by 1
    int prefixXor = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        prefixXor = prefixXor ^ a[i];

        int x = prefixXor ^ k;
        count += mpp[x];

        // adding prefixXor into hash set
        mpp[prefixXor]++;
    }

    return count;
}

int main()
{
    vector<int> array = {4, 2, 2, 6, 4};
    cout << optimal(array, 6);
    return 0;
}