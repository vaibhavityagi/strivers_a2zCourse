// 4 sum problem

#include <bits/stdc++.h>
using namespace std;

// brute
vector<vector<int>> brute(vector<int> &a, int t)
{
    int n = a.size();
    set<vector<int>> st;

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            for (int k = j + 1; k < n - 1; k++)
            {
                if (a[i] + a[j] + a[k] + a[k + 1] == t)
                {
                    vector<int> temp = {a[i], a[j], a[k], a[k + 1]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans = {st.begin(), st.end()};
    return ans;
}

// optimal - using two pointer approach
vector<vector<int>> fourSum(vector<int> &a, int t)
{
    int n = a.size();
    vector<vector<int>> ans;

    sort(a.begin(), a.end());

    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && a[i] == a[i - 1]) // to avoid repeating quads
            continue;
        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && a[j] == a[j - 1]) // to avoid repeating quads
                continue;

            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = a[i] + a[j] + a[left] + a[right];
                if (sum < t)
                    left++;
                else if (sum > t)
                    right--;
                else // sum == target
                {
                    vector<int> temp = {a[i], a[j], a[left], a[right]};
                    ans.push_back(temp);
                    left++;
                    right--;

                    // to eliminate repeating quads
                    while (left < right && a[left] == a[left - 1])
                        left++;
                    while (left < right && a[right] == a[right + 1])
                        right++;
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> array = {1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4};
    vector<vector<int>> res = fourSum(array, 9);
    for (auto temp : res)
    {
        for (int ele : temp)
            cout << ele << " ";

        cout << endl;
    }
    return 0;
}