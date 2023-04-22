#include <bits/stdc++.h>
using namespace std;

// count the digits
int q1(int n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n /= 10;
    }
    return count;
}

// reversal of a number
int q2(int n)
{
    int revNum = 0;
    int lastDigit;
    while (n != 0)
    {
        lastDigit = n % 10;
        n /= 10;
        revNum = (revNum * 10) + lastDigit;
    }
    return revNum;
}

void isPalindrone(int n)
{
    int copy = n;
    int revNum = 0;
    int lastDigit;
    while (n != 0)
    {
        lastDigit = n % 10;
        n /= 10;
        revNum = (revNum * 10) + lastDigit;
    }
    if (revNum == copy)
        cout << "true";
    else
        cout << "false";
}

void armstrong(int n)
{
    int lastDigit;
    int sum = 0;
    int copy = n;
    while (n != 0)
    {
        lastDigit = n % 10;
        sum = sum + (lastDigit * lastDigit * lastDigit);
        n /= 10;
    }
    if (sum == copy)
        cout << "Armstrong number!";
    else
        cout << "Not an armstrong number";
}

void divisors(int n)
{
    // brute force
    /*
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cout << i << " ";
    }
    */

    // better apporach
    vector<int> v;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (n != n / i)
                v.push_back(n / i);
        }
    }

    // sorting the elements
    sort(v.begin(), v.end());
    for (auto it : v)
        cout << it << " ";
}

void isPrime(int n)
{
    // brute force --> TC = O(N)
    /*
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            count++;
    }
    if (count > 2)
        cout << "No";
    else
        cout << "Yes";
    */

    // better approach
    int count = 0;
    vector<int> v;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count++;
            if (n != n / i)
                count++;
        }
    }

    if (count > 2)
        cout << "No, not a prime number!";
    else
        cout << "Yes, a prime number!";
}

int gcd(int n1, int n2)
{
    // brute force --> TC = O(min(n1, n2))
    /*
    //as 2 numbers me koi factor common nhi hoga toh 1 toh always common hoga
    int ans = 1;
    for (int i = 1; i <= min(n1, n2); i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
            ans = i;
    }
    cout << ans;
    */

    // using Euclidean ALgorithm - best approach
    if (n2 == 0)
        return n1;
    return gcd(n2, n1 % n2);
}

int main()
{
    int num1, num2;
    cout << "Enter the number: ";
    cin >> num1 >> num2;
    // cout << q2(num) << endl;
    cout << gcd(num1, num2);
    return 0;
}