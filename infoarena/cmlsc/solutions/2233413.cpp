#include <fstream>
#include <iostream>
#include <stack>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main()
{

    ifstream _in("cmlsc.in");
    ofstream _out("cmlsc.out");

    int size1, size2;

    int res = 0;

    _in >> size1 >> size2;
    int arr1[size1], arr2[size2];

    for (int i = 0; i < size1; i++)
        _in >> arr1[i];
    for (int i = 0; i < size2; i++)
        _in >> arr2[i];

    int temp[size1 + 1][size2 + 1];
    for (int i = 0; i <= size1; i++)
    {
        for (int j = 0; j <= size2; j++)
        {
            if (i == 0 || j == 0)
                temp[i][j] = 0;
            else if (arr1[i - 1] == arr2[j - 1])
                temp[i][j] = temp[i - 1][j - 1] + 1;
            else
                temp[i][j] = max(temp[i - 1][j], temp[i][j - 1]);

            res = max(res, temp[i][j]);
        }
    }

    int sol[res];
    int k = res-1;
    int i=size1; int j=size2;
    while(i>0 && j>0)
    {
   
            if (arr1[i - 1] == arr2[j - 1])
                sol[k] = arr1[i - 1], i--, j--, k--;
            else if (temp[i - 1][j] > temp[i][j - 1])
                i--;
            else
                j--;
   
    }
    //_out << res << endl;
    for (int i = 0; i < res; i++)
    {
       // cout << sol[i] << endl;
        _out << sol[i] << " ";
    }

    _in.close();
    _out.close();
    //cin >> res;
    return 0;
}