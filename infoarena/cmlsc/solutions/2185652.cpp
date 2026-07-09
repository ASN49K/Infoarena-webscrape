                       /*LCS (Longest Common Subsequence) program [Using Dynamic Programming]*/

#include <fstream>
#define table_size 1024 // The size of the table from which i will find the LCS.
int i, j;
using namespace std;

int LCS (int a[], int b[], int m, int n, int length, int subsir[])
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int lcs_arr[m + 1][n + 1];

    /*Fill row 0 and line 0 with the value 0*/
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                lcs_arr[i][j] = 0;
        }
    }

    /*Filling the table starting from line 1, row 1*/
    for (i = 1; i <= m; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (a[i - 1] == b[j - 1])
                lcs_arr[i][j] = lcs_arr[i - 1][j - 1] + 1;
            else
                lcs_arr[i][j] = max(lcs_arr[i][j - 1], lcs_arr[i - 1][j]);
        }
    }

    /*Finding the Longest Common Subsequence (LCS)*/
    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (lcs_arr[i][j] == lcs_arr[i][j - 1])
            --j;
        else if (lcs_arr[i][j] == lcs_arr[i - 1][j])
            --i;
        else
        {
            ++length;
            subsir[length - 1] = a[i - 1];
            --i;
            --j;
        }
    }
    /*Showing the length of the LCS and the LCS itself*/
    fout<<length<<endl;
    for (i = length; i > 0; --i)
        fout<<subsir[i - 1]<<" ";
}

int max(int a, int b)
{
    return (a<b)?b:a;
}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int m, n; //Desired elements for the two sequences ("m" for array "a" and "n" for array "b" ).
    int a[table_size], b[table_size]; // Two sequences from which the longest common subsequence will be extracted.
    int sub_s[table_size]; // This variable stores the LCS.
    int length = 0; // The length of the LCS.
    fin>>m>>n;

 /*Reading the elements for array "a" and array "b"*/
    for (i = 0; i < m; ++i)
        fin>>a[i];
    for (i = 0; i < n; ++i)
        fin>>b[i];

    LCS(a, b, m, n, length, sub_s);
}

