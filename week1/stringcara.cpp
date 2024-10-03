// Prof.Azhar
// CSC 211 H
// Abdoulaye

#include <iostream>
#include <string>
using namespace std;

string christmas_tree(int n)
{
    string tree;
    for (int i = 1; i <= n; ++i)
    {
        tree += string(n - i, ' ');
        tree += string(2 * i - 1, '*');
        tree += '\n';
    }

    tree += string(n - 1, ' ') + "*" + '\n';

    return tree;
}

int main()
{
    cout << christmas_tree(3) << endl;
    cout << christmas_tree(5) << endl;
    return 0;
}