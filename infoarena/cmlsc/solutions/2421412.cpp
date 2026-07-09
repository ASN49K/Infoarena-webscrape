#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

short int matrix[1025][1025];
int main()
{
    int n, m;
    short int arr1[1025], arr2[1025];
    vector<short int> rez;

    f >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        f >> arr1[i];
    }

    for (int i = 1; i <= m; ++i)
    {
        f >> arr2[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (arr1[i] == arr2[j])
            {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }
            else
            {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }

    for (int i = n, j = m; i;)
    {
        if (arr1[i] == arr2[j])
        {
            rez.push_back(arr1[i]);
            --i;
            --j;
        }
        else if (matrix[i - 1][j] < matrix[i][j - 1])
        {
            --j;
        }
        else
        {
            --i;
        }
    }

    g << rez.size() << '\n';
    reverse(rez.begin(), rez.end());
    for (auto a : rez)
    {
        g << a << " ";
    }

    return 0;
}