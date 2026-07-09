#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int m,n,X[1040],Y[1040],lcs[1040],index, L[1040][1040];
/*
void LCS(int X[], int Y[], int m, int n )
{
    int L[1040][1040];
    for(int i=0; i <=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
                L[i][j]=0;
            else if(X[i-1]==Y[j-1])
                L[i][j]= L[i-1][j-1] +1;
            else
                L[i][j]= max(L[i-1][j],L[i][j-1]);
        }
    }
    int i = m, j = n;
    while (i > 0 && j > 0)
    {

        if (X[i] == Y[j])
        {
            lcs[++index]= X[i];
            i--;
            j--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    fout<<L[m][n];
    fout<<endl;
    for(int i=index; i>=1; i--)
        fout <<lcs[i] <<" ";
}
*/
int main()
{
    fin>>m>>n;
    for(int i=1; i<=m ; ++i)
        fin>>X[i];
    for(int j=1; j<=n; ++j)
        fin>>Y[j];
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
        {
            if(X[i]==Y[j])
                L[i][j]= 1+ L[i-1][j-1];
            else
                L[i][j]= max(L[i-1][j], L[i][j-1]);
        }
    int i=m;
    int j=n;
    while( i>0 && j>0)
    {
        if(X[i]==Y[j])
        {
            lcs[++index]=X[i];
            i--;
            j--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    fout<<L[m][n]<<endl;
    for(int i=index;i>=1; --i)
        fout<<lcs[i]<<" ";
    fin.close();
    fout.close();
    return 0;
}
