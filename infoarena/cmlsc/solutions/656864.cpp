#include<iostream>
#include<fstream>
using namespace std;
#define maxn 1025

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

typedef struct { short val; } ceva;

long rez,R[maxn];
short A[maxn];
short B[maxn];
long n,m;
long i,j,act,prim;
long BST[maxn][maxn];
long P[maxn];
long T[maxn];
int main()
{
    in>>n>>m;
    for ( i=1; i<=n; i++ )
        in>>A[i];
    for ( j=1; j<=m; j++ )
        in>>B[j];
    for ( i=1; i<=n; i++ )
    {
        for ( j=1; j<=m; j++ )
        {
            if (A[i]==B[j] )
                BST[i][j]=1+BST[i-1][j-1];
            else
                BST[i][j]=max(BST[i][j-1],BST[i-1][j]);
        }
    }
    for ( i=n,j=m; i; )
    {
        if ( A[i]==B[j] )
        {
            rez++;
            R[rez]=B[j]; i--; j--;
        }
        else if ( BST[i-1][j]<BST[i][j-1] )
            j--;
        else
            i--;
    }
    out<<rez<<"\n";
    for ( ; rez; --rez )
        out<<R[rez]<<" ";
    return 0;
}
