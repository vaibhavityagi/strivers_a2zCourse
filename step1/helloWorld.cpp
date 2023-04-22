#include <iostream>
// to avoid using std::
using namespace std;

int main()
{
    // std::cout << "Hello World!"
    //           << "\n";
    // another way for inserting a new line
    // std::cout << "Hello World!" << std::endl;
    // std::cout << "Hello World!";
    // cout << "Hello World!"
    //      << "\n"
    //      << "Hello again!"
    //      << "\n";
    // int x, y;
    // cin >> x >> y;
    // cout << "Value of x: " << x << "\n"
    //      << "Value of y: " << y;

    //------------------- dataTypes -----------------------
    // picks up words until a space is not encountered
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << " " << s2;

    // picks up words until an enter is not encountered
    string str;
    getline(cin, str);
    cout << str;
    return 0;
}