// pascal's triangle

#include <bits/stdc++.h>
using namespace std;

// ------------------------ variation one -------------------------
// find the element at (r,c) position

// brute force
/*
long long fact(int x)
{
    if (x == 1 || x == 0)
        return 1;
    return x * fact(x - 1);
}

long long nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

long element(int row, int col)
{
    long long ans = nCr(row - 1, col - 1);
    return ans;
}
*/

// optimal
long long nCr(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

long long element(int row, int col)
{
    long long ans = nCr(row - 1, col - 1);
    return ans;
}

// ------------------------ variation two -------------------------
// print the nth row

// brute force - using the (r-1)C(n-1) formula for finding each element
void nthRow(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << nCr(n - 1, i) << " ";
    }
}

// optimal
void nthRowO(int n)
{
    int res = 1;
    cout << res << " ";
    for (int i = 1; i < n; i++)
    {
        res = res * (n - i);
        res = res / i;
        cout << res << " ";
    }
}

// ------------------------ variation three -------------------------
// print the pascal triangle for the give number of rows

// brute - using the (r-1)C(c-1) formula (i.e. first variation)
void pascal(int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << nCr(i, j) << " ";
        }

        cout << endl;
    }
}

// optimal - using second variation
vector<int> generateRow(int n)
{
    vector<int> row;
    long long res = 1;
    row.push_back(1);

    for (int i = 1; i < n; i++)
    {
        res = res * (n - i);
        res = res / i;
        row.push_back(res);
    }

    return row;
}

vector<vector<int>> pascalO(int row)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= row; i++)
    {
        ans.push_back(generateRow(i));
    }

    return ans;
}

int main()
{
    // cout << element(5, 3) << endl;
    // nthRowO(6);
    // cout << endl;
    vector<vector<int>> triangle = pascalO(6);
    for (auto it : triangle)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}