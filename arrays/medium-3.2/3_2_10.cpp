// longest consecutive sequence in an array

#include <bits/stdc++.h>
using namespace std;

// brute force - sorting
int brute(vector<int> &arr)
{
    int n = arr.size();
    int curlen = 1;
    int ans = 1;

    // if the array is empty
    if (n == 0)
        return 1;

    // sorting the array
    sort(arr.begin(), arr.end());

    // finding the longest sequence in the sorted array
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == (arr[i + 1] - 1))
            curlen++;
        else if (arr[i] == arr[i + 1])
            curlen += 0;
        else if (arr[i] != (arr[i + 1] - 1))
            curlen = 1;

        ans = max(ans, curlen);
    }

    return ans;
}

// optimal
int optimal(vector<int> &a)
{
    int ans = 1;
    unordered_set<int> st;

    // inserting elements into the set
    for (int ele : a)
    {
        st.insert(ele);
    }

    // iterating over each element
    for (int ele : st)
    {
        /*
        if (st.find(ele - 1) != st.end()) // ie the element is present in the set
        {
            // do nothing
        }
        */

        // ele-1 is not present in the set so find ele+1
        if (st.find(ele - 1) == st.end())
        {
            int curlen = 1;
            int x = ele;

            // while loop runs until we find an ele that is not in the set
            while (st.find(x + 1) != st.end())
            {
                curlen++;
                x++;
            }

            ans = max(ans, curlen);
        }
    }

    return ans;
}

int main()
{
    vector<int> array = {15, 6, 2, 1, 16, 4, 2, 29, 9, 12, 8, 5, 14, 21, 8, 12, 17, 16, 6, 26, 3};
    cout << optimal(array);
    return 0;
}
