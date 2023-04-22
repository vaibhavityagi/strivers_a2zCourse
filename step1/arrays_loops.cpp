#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    //array
    int arr[][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << arr[0][1];
    */

    // loops - for, while, do while
    // for loop
    for (int i = 1; i <= 5; i++)
    {
        cout << "fuck you betty! " << i << endl;
    }
    // count << i; //gives an error as i is defined in the loop its scope is limited to the for loop block

    // while loop
    int j = 1;
    while (j <= 5)
    {
        cout << "fuck you betty! " << j << endl;
        j++;
    }

    // do while loop
    int k = 2;
    do
    {
        cout << "fuck you betty! " << k << endl;
        k++;
    } while (k <= 2);
    cout << k; // 3
    return 0;
}