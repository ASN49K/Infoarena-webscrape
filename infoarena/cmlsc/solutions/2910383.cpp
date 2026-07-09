#include <bits/stdc++.h>
using namespace std;
#define max_size 1025
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out"); 
int m,n,i,j,lmx;
int A[max_size],B[max_size],M[max_size][max_size],R[max_size];

int main()
{
    fin >> m >> n ;
    for (i=1;i<=m;i++) fin>> A[i];
    for (j=1;j<=n;j++) fin>> B[j];
    for (i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (A[i]==B[j])
            {
                M[i][j]=M[i-1][j-1]+1;
            }
            else M[i][j]=max(M[i-1][j],M[i][j-1]);
        }
    }
    i=m;
    j=n;
    while (i>0 && j>0)
    {
        if (A[i]==B[j])
        {
            R[++lmx]=A[i];
            i--;
            j--;
        }
        else if (M[i-1][j]>M[i][j-1])
        {
            i--;
        }
        else j--;
    }
    fout<<lmx<<"\n";
    for (i=lmx;i>0;i--)
    {
        fout << R[i]<<" ";
    }
    fout<<"\n";
    return 0;
}