// algorithm for the longest subsequence in a sequence
#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");
 
int n,m,a[1024],b[1024],d[1024][1024],sir[1024],bst;
 
int main ()
{
    int i,j;
    fin >> n >>m;
    for (i = 1; i <= n; i++) fin >> a[i]; // reading first array
    for (i = 1; i <= m; i++) fin >> b[i]; // reading second array
 
    for (i = 1; i <= n; i++) // there we have a matrix where we compared the values from that to sequences
        for (j = 1; j <= m; j++)
            if (a[i] == b[j]) d[i][j] = 1 + d[i-1][j-1]; // if the values are the same then we've got the increased value ith 1 by matrix value from i-1 and j-1
            else if (d[i-1][j] > d[i][j-1]) d[i][j] = d[i-1][j]; /* if the values are different then we compare them and we chose the bigger value from the matrix
                                                                    left and up*/
            else d[i][j] = d[i][j-1];
 
    for (i = n, j = m; i > 0; ) // after we've created the matrix we go back from the last matrix value to see where the valuers are coming from
        if (a[i] == b[j]) // if the values come from there that means that them are equals and we add the value to the LCS
            sir[++bst] = a[i], --i, --j; // we go to where elements come from
        else if (d[i-1][j] < d[i][j-1])// else we go to the maximum between matrix values
            --j; // by left
        else
            --i; // or by top
 
    fout << bst << endl; // length of LCS
    for (i = bst ; i >0 ; i--) // LCS values
        fout << sir[i] << ' ';
 
    return 0;
}
