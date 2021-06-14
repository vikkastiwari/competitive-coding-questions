// question link: https://practice.geeksforgeeks.org/problems/sorted-matrix2333/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sortedMatrix(vector<vector<int>> mat)
{
    // code
    int n = mat.size();
    int m = mat[0].size();

    vector<int> vmat;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vmat.push_back(mat[i][j]);
        }
    }
    sort(vmat.begin(), vmat.end());

    vector<vector<int>> matrix;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            temp.push_back(vmat[k++]);
        }
        matrix.push_back(temp);
        temp.clear();
    }

    return matrix;
}

int main()
{
    vector<vector<int>> n = {{10, 20, 30, 40},
                             {15, 25, 35, 45},
                             {27, 29, 37, 48},
                             {32, 33, 39, 50}};

    vector<vector<int>> sortedMat = sortedMatrix(n);

    for (int i = 0; i < n.size(); i++)
    {
        for (int j = 0; j < n[0].size(); j++)
        {
            cout << sortedMat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
