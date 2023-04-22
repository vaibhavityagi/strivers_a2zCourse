#include <bits/stdc++.h>
using namespace std;

// print a string for n number of times
int cnt = 1;
void printName(string name, int n)
{
    if (cnt > n)
        return;
    cout << name << endl;
    cnt++;
    printName(name, n);
}

// print 1 to N linerly
void printNos(int n)
{
    if (cnt > n)
        return;
    cout << cnt << " ";
    cnt++;
    printNos(n);
}

// print N to 1 linearly
void printNosBack(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    printNosBack(n - 1);
}

// sum of n natural numbers

// paramaterized form
void sumNosP(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    sumNosP(i - 1, sum + i);
}

// functinal form
int sumNosF(int n)
{
    if (n == 0)
        return 0;
    return n + sumNosF(n - 1);
}

// factorial of n
int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

// reversing an array

// without recursion // TC = O(n), SC = O(n) [extra array used]
void reverseArr(int arr[], int n)
{
    int ans[n];
    for (int i = n; i > 0; i--)
    {
        ans[n - i] = arr[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

// using two pointers and swapping the values at those pointers, TC = O(n), SC = O()
void revArr2(int arr[], int n)
{
    int p1 = 0, p2 = n - 1;
    while (p1 != p2)
    {
        swap(arr[p1], arr[p2]);
        p1++, p2--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// two pointer approach but using recursion
void revArr3(int arr[], int start, int end)
{
    if (start >= end / 2)
        return;
    swap(arr[start], arr[end - 1]);
    revArr3(arr, start + 1, end - 1);
}

// fibonacci series
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// check is a passed string is palindrome or not
bool isPalindrome(string s)
{
    return;
}

int main()
{
    int num;
    string name;
    cout << "Enter a string: ";
    cin >> name;
    // cout << "Enter a number: ";
    // cin >> num;
    // printName(name, num);
    // printNos(num);
    // printNosBack(num);
    // sumNosP(num, 0);
    // cout << sumNosF(num);
    // cout << factorial(num);

    // int array[] = {1, 2, 3, 4, 5};
    // reverseArr(array, 5);
    // revArr2(array, 5);
    // revArr3(array, 0, 5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << array[i] << " ";
    // }
    // cout << fib(num);
    cout << isPalindrome(name);
}