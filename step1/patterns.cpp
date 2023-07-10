#include <iostream>
using namespace std;

void pattern1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << "* ";
        cout << endl;
    }
}

void pattern5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
            cout << "* ";
        cout << endl;
    }
}

void pattern6A(int n)
{
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            cout << k;
            k++;
        }
        cout << endl;
        k = 1;
    }
}

// better approach
void pattern6B(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
            cout << j;
        cout << endl;
    }
}

void pattern7(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        // star
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << "*";
        // space
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        cout << endl;
    }
}

void pattern8(int n)
{

    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < i; j++)
            cout << " ";
        // stars
        for (int j = 1; j <= 2 * n - (2 * i + 1); j++)
            cout << "*";
        // space
        for (int j = 0; j < i; j++)
            cout << " ";
        cout << endl;
    }
}

void pattern9(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        // star
        for (int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        // space
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < i; j++)
            cout << " ";
        // stars
        for (int j = 1; j <= 2 * n - (2 * i + 1); j++)
            cout << "*";
        // space
        for (int j = 0; j < i; j++)
            cout << " ";
        cout << endl;
    }
}

void pattern10A(int n)
{
    // not passing all the test cases in gfg
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
    for (int i = 1; i <= n; i++) // change it to 1 to n-1
    {
        for (int j = 1; j <= n - i; j++)
            cout << "* ";
        cout << endl;
    }
}

void pattern10B(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
            cout << "* ";
        cout << endl;
    }
}

void pattern11(int n)
{
    int start = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            start = 0;
        else
            start = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}

void pattern12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // numbers
        for (int j = 1; j <= i; j++)
            cout << j;
        // space
        for (int j = 1; j <= 2 * (n - i); j++)
            cout << " ";
        // numbers
        for (int j = i; j >= 1; j--)
            cout << j;
        cout << endl;
    }
}

void pattern13(int n)
{
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << k << " ";
            k++;
        }
        cout << endl;
    }
}

void pattern14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
            cout << ch;
        cout << endl;
    }
}

void pattern15(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++)
            cout << ch;
        cout << endl;
    }
}

void pattern16(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
            cout << char('A' + i);
        cout << endl;
    }
}

// 17 samjhna hai
void pattern17(int n)
{
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";

        // letters
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * n + 1; j++)
        {
            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }

        // spaces
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";

        cout << endl;
    }
}

void pattern18(int n)
{
    // mine
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + (n - 1);
        for (int j = i; j >= 0; j--)
        {
            cout << char(ch - j) << " ";
        }
        cout << endl;
    }

    // striver's
    /*
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'E' - i; ch <= 'E'; ch++)
            cout << ch << " ";
        cout << endl;
    }
    */
}

void pattern19(int n)
{
    // downside
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 0; j < n - i; j++)
            cout << "*";
        // space
        for (int j = 0; j < 2 * i; j++)
            cout << " ";
        // stars
        for (int j = 0; j < n - i; j++)
            cout << "*";
        cout << endl;
    }

    // upside
    for (int i = 1; i <= n; i++)
    {
        //  stars
        for (int j = 1; j <= i; j++)
            cout << "*";
        // space
        for (int j = 1; j <= 2 * (n - i); j++)
            cout << " ";
        // stars
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }
}

void pattern20(int n)
{
    // upside
    for (int i = 1; i <= n; i++)
    {
        //  stars
        for (int j = 1; j <= i; j++)
            cout << "*";
        // space
        for (int j = 1; j <= 2 * (n - i); j++)
            cout << " ";
        // stars
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }

    // downside
    for (int i = 1; i <= n - 1; i++)
    {
        // stars
        for (int j = 0; j < n - i; j++)
            cout << "*";
        // space
        for (int j = 0; j < 2 * i; j++)
            cout << " ";
        // stars
        for (int j = 0; j < n - i; j++)
            cout << "*";
        cout << endl;
    }
}

void pattern21(int n)
{
    // my approach

    for (int i = 1; i <= n; i++)
    {
        int stars = 1;
        int space = n - 2;
        if (i == 1 || i == n)
        {
            stars = n;
            space = 0;
        }

        // stars
        for (int j = 1; j <= stars; j++)
            cout << "*";

        // space
        for (int j = 1; j <= space; j++)
            cout << " ";

        // stars
        if (stars != n)
        {
            for (int j = 1; j <= stars; j++)
                cout << "*";
        }

        cout << endl;
    }

    // striver's approach
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || j == n - 1 || i == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void pattern22(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            cout << "*";
        }
    }
}

int main()
{
    int num;
    cout << "Enter the number of lines: ";
    cin >> num;
    pattern5(num);
    return 0;
}
