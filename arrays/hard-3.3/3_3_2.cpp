// majority element (elememnt whose number of occurences is greater than n/3)

#include <bits/stdc++.h>
using namespace std;

// brute
vector<int> brute(vector<int> &v)
{

    // my brute solution, it can be further optimized
    /*
        vector<int> ans;

        int n = v.size();
        int maj = floor(n / 3);

        unordered_map<int, int> mpp;

        // iterating over the vector; key = ele, value = count
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i; j < n; j++)
            {
                if (v[i] == v[j])
                    count++;
            }

            mpp.insert({v[i], count});
        }

        // iterating over the map to find which elements have occurences greater than n/3
        for (auto it : mpp)
        {
            if (it.second > maj)
                ans.push_back(it.first);
        }

        return ans;
    */

    // stiver's more optimized version of the same idea
    vector<int> ans;

    int n = v.size();
    int minOcc = floor(n / 3) + 1;

    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++; // if the element doesn't appear before, map considers its value as zero and adds 1

        // checking if v[i] has minOcc, then add it to the ans
        if (mpp[v[i]] == minOcc)
            ans.push_back(v[i]);

        // since there can be only two elements at max in the solution vector
        if (ans.size() == 2)
            break;
    }

    return ans;
}

// optimal - extended boyer moore's voting algo
vector<int> majEle(vector<int> &v)
{
    int n = v.size();
    int ele1 = INT_MIN, ele2 = INT_MIN;
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && ele2 != v[i])
        {
            ele1 = v[i];
            cnt1 = 1;
        }

        else if (cnt2 == 0 && ele1 != v[i])
        {
            ele2 = v[i];
            cnt2 = 0;
        }

        else if (ele1 == v[i])
            cnt1++;

        else if (ele2 == v[i])
            cnt2++;

        else
        {
            cnt1--;
            cnt2--;
        }
    }

    // manual check to make sure both the elements are greater than n/3
    vector<int> ans;

    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (ele1 == v[i])
            cnt1++;
        else if (ele2 == v[i])
            cnt2++;
    }

    if (cnt1 > floor(n / 3))
        ans.push_back(ele1);
    if (cnt2 > floor(n / 3))
        ans.push_back(ele2);

    return ans;
}

int main()
{
    vector<int> array = {1, 1, 3, 3, 1, 2, 2, 2};
    vector<int> result = majEle(array);
    for (int it : result)
        cout << it << " ";
    return 0;
}