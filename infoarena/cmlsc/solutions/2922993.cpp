#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int maximi(int a, int b)
{
    if(a==b)
        return a;
    if(a>b)
        return a;
    if(b>a)
        return b;
}
int LCS(int X[], int Y[], int m, int n )
{
    int i, j;
    int L[m+1][n+1];
    for( i=0; i <=m; ++i)
    {
        for( j=0; j<=n; ++j)
        {
            if(i==0 || j==0)
                L[i][j]=0;
            else if(X[i-1]==Y[j-1])
                L[i][j]= L[i-1][j-1] +1;
            else
                L[i][j]= max(L[i-1][j],L[i][j-1]);
        }
    }
    return L[m][n];

}
int main()
{
    int m,n;
    int X[267],Y[267];
    fin>>m>>n;
    for(int i=1;i<=m ;++i)
        fin>>X[i];
    for(int j=1; j<=n; ++j)
        fin>>Y[j];
    fout<< LCS(X,Y,m,n);
    return 0;
}
