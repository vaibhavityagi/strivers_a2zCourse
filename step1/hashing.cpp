#include <bits/stdc++.h>
using namespace std;

int main()
{

    // number hashing
    /*
    int n;
    cout << "Input the length of array: ";
    cin >> n;
    int arr[n];
    cout << "Input the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // precomputation
    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    int q;
    cout << "Number of queries: ";
    cin >> q;
    while (q--)
    {
        int number;
        cout << "Number whose occurences is to be searched in the array: ";
        cin >> number;

        // fetch
        cout << "Number of occurences of " << number << ": ";
        cout << hash[number] << endl;
    }
    */

    // character hashing

    // brute force
    /*
    int count = 0;
    string s;
    char q;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Your looking for? ";
    cin >> q;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == q)
            count++;
    }
    cout << count;
    */

    // using array hashing
    /*
    string s;
    cout << "Enter a string: ";
    cin >> s;

    // precomputation
    int hash[26] = {0};
    // iterating over the string
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
    }

    int q;
    cout << "Enter the number of queries: ";
    cin >> q;
    while (q--)
    {
        char ch;
        cout << "Character to be searched for? ";
        cin >> ch;

        // fetch
        cout << "Number of occurences of " << ch << ": ";
        cout << hash[ch - 'a'] << endl;
    }
    */

    // using maps

    /*
        //number hashing

        // inputting the array
        int len;
        cout << "Enter the length of the array: ";
        cin >> len;
        int arr[len];
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < len; i++)
        {
            cin >> arr[i];
        }

        // pre-computation
        map<int, int> mpp;
        for (int i = 0; i < len; i++)
        {
            mpp[arr[i]]++;
        }

        int q;
        cout << "Enter the number of queries: ";
        cin >> q;
        while (q--)
        {
            int number;
            cout << "Enter the number to be searched for: ";
            cin >> number;

            // fetch
            cout << mpp[number] << endl;
        }
    */

    /*

     // character hashing

     // input
     string s;
     cout << "Enter a string: ";
     cin >> s;

     // pre-computation
     unordered_map<char, int> mpp;
     for (int i = 0; i < s.size(); i++)
     {
         mpp[s[i]]++;
     }

     int q;
     cout << "Enter the number of queries: ";
     cin >> q;
     while (q--)
     {
         char ch;
         cout << "Enter the character to be searched for: ";
         cin >> ch;

         // fetch
         cout << mpp[ch] << endl;
     }
     */

    // highest frequency and lowest frequency element (not sure)
    int len;
    cout << "Enter the length of the array: ";
    cin >> len;

    int arr[len];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    // pre-computation
    unordered_map<int, int> mpp;
    for (int i = 0; i < len; i++)
    {
        mpp[arr[i]]++;
    }

    // iterating over the map
    int max = 1, min = 1;
    for (auto it : mpp)
    {
        if (it.second > max)
            max = it.first;
        if (it.second < min)
            min = it.first;
    }
    cout << "Maximum frequency element: " << mpp[max] << endl;
    cout << "Minimum frequency element: " << mpp[min];
    return 0;
}