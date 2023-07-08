// print the matrix in spiral manner

#include <bits/stdc++.h>
using namespace std;

// something I tried - doesnt work
vector<vector<int>> spiral(vector<vector<int>> &mat, int r, int c)
{
    // first row
    for (int i = 0; i <= 0; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mat[i][j] << " ";
        }
    }

    // outer most col
    for (int i = 1; i < r; i++)
    {
        for (int j = c - 1; j <= c - 1; j++)
        {
            cout << mat[i][j] << " ";
        }
    }

    // bottom most row
    for (int i = r - 1; i <= r - 1; i++)
    {
        for (int j = c - 2; j >= 0; j--)
        {
            cout << mat[i][j] << " ";
        }
    }

    // outermost col
    for (int i = r - 2; i > 0; i--)
    {
        for (int j = c - c; j <= 0; j++)
        {
            cout << mat[i][j] << " ";
        }
    }
}

// optimal
//  right -> bottom -> left -> top
vector<vector<int>> spiralOpt(vector<vector<int>> &mat)
{
    int r = mat.size();
    int c = mat[0].size();
    int left = 0, top = 0;
    int bottom = r - 1;
    int right = c - 1;

    while (left <= right && top <= bottom)
    {
        // right
        for (int i = left; i <= right; i++)
        {
            cout << mat[top][i] << " ";
        }
        top++;

        // bottom
        for (int i = top; i <= bottom; i++)
        {
            cout << mat[i][right] << " ";
        }
        right--;

        // left
        if (top <= bottom) // check for edge cases; given matrix = [1, 2, 3, 4, 5]
        {
            for (int i = right; i >= left; i--)
            {
                cout << mat[bottom][i] << " ";
            }
            bottom--;
        }

        // top
        if (left <= right) // check for edge cases
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << mat[i][left] << " ";
            }
            left++;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5}};

    spiralOpt(matrix);
    return 0;
}