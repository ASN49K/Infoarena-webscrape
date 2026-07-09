#include <iostream>
#include <fstream>
#define NMAX 1024

using namespace std;

int A[NMAX];
int B[NMAX];
int m,n;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int Max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

void LCS(int A[],int B[],int m,int n)
{
    int i,j;
    int L[m+1][n+1];
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
                L[i][j]=0;
            else if(A[i-1]==B[j-1])
                L[i][j]=L[i-1][j-1]+1;
            else
                L[i][j]=Max(L[i-1][j],L[i][j-1]);
        }
    int index=L[m][n];
    int aux=index;
    out<<index<<"\n";
    i=m;
    j=n;
    int sir[index];
    while(i>0&&j>0)
    {
        if(A[i-1]==B[j-1])
        {
            sir[index-1]=A[i-1];
            index--;
            i--;
            j--;
        }
        else if(L[i-1][j]>L[i][j-1])
            i--;
        else
            j--;
    }
    for(int i=0;i<aux;i++)
        out<<sir[i]<<" ";

}

int main()
{
    in>>m>>n;
    for(int i=0;i<m;i++)
        in>>A[i];
    for(int j=0;j<n;j++)
        in>>B[j];
    LCS(A,B,m,n);

    return 0;
}
