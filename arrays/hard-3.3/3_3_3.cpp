// 3 sum problem

#include <bits/stdc++.h>
using namespace std;

// brute
// problem: repeating triplets (solved using set)
vector<vector<int>> brute(vector<int> &a)
{
    int n = a.size();

    set<vector<int>> st;

    for (int i = 0; i < n - 2; i++)
    {
        int ele1 = a[i];
        for (int j = i + 1; j < n - 1; j++)
        {
            int ele2 = a[j], ele3 = a[j + 1];

            if (ele1 + ele2 + ele3 == 0)
            {
                vector<int> temp = {ele1, ele2, ele3};
                // for storing only uniques triplets
                // sorting so that in case one triplet is {-1, 0, -1} and other is {-1, -1, 0}; there are the same thing and sorting would make sure they are treated in the same way
                // then storing in a set as it only stores uniques elements
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
        }
    }

    vector<vector<int>> ans = {st.begin(), st.end()};
    return ans;
}

// another approach
vector<vector<int>> better(vector<int> &a)
{
    int n = a.size();

    set<vector<int>> st;
    unordered_set<int> hashSet;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int third = -(a[i] + a[j]);
            if (hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {a[i], a[j], third};
                // avoid duplicates
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(a[j]);
        }
    }

    vector<vector<int>> ans = {st.begin(), st.end()};
    return ans;
}

// optimal - using two pointer approach
vector<vector<int>> threeSum(vector<int> &a)
{
    int n = a.size();
    vector<vector<int>> ans;

    sort(a.begin(), a.end());

    for (int i = 0; i < n - 2; i++)
    {
        // in case the next i is the same is the previous i (since we dont want to take repeating triplets)
        if (i > 0 && a[i] == a[i - 1])
            continue; // skip this iteration

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = a[i] + a[left] + a[right];
            if (sum < 0)
                left++;
            else if (sum > 0)
                right--;
            else
            {
                vector<int> temp = {a[i], a[left], a[right]};
                ans.push_back(temp);
                left++;
                right--;
                // so that we dont take the same elements again
                while (left < right && a[left] == a[left - 1])
                    left++;
                while (left < right && a[right] == a[right + 1])
                    right--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> array = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2};
    vector<vector<int>> res = threeSum(array);
    for (auto temp : res)
    {
        for (int ele : temp)
            cout << ele << " ";

        cout << endl;
    }
    return 0;
}