#include <bits/stdc++.h>
#define ll long long
#define N 4
using namespace std;

/* 
cell 1 means Source.
cell 2 means Destination.
cell 3 means Blank cell.
cell 0 means Blank Wall.
*/

int main()
{
    int M[N][N] = {{0, 3, 0, 1},
                   {3, 0, 3, 3},
                   {2, 3, 3, 3},
                   {0, 3, 3, 3}};

    (findPath(M) == true) ? cout << "Yes" : cout << "No" << endl;

    return 0;
}