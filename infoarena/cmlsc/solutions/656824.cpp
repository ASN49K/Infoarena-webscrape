// 12:18
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
            if ( A[i]==B[j] )
            {
                BST[i][j]=BST[i-1][j-1]+1;
                T[j]=j;
                P[j]=T[j-1];
               // cout<<"!";
            }
            else
            {
                if ( BST[i-1][j] > BST[i][j] )
                {
                    BST[i][j]=BST[i-1][j];
                }
                if ( BST[i][j-1] > BST[i][j] )
                {
                    BST[i][j]=BST[i][j-1];
                    T[j]=T[j-1];
                    P[j]=T[j-1];
                }
                if ( BST[i-1][j-1] > BST[i][j] )
                {
                    BST[i][j]=BST[i-1][j-1];
                    T[j]=T[j-1];
                    P[j]=T[j-1];
                }


            }
        }
        /*for ( j=1; j<=m; j++ )
            cout<<BST[i][j]<<" "<<P[j]<<"\n";
        cout<<"\n\n";*/
    }
    for ( i=1; i<=m; i++ )
        if ( BST[n][i] > act )
        {
            act=BST[n][i];
            prim=i;
        }
    out<<act<<"\n";
    while ( P[prim]!=0 )
    {
        rez++;
        R[rez]=B[prim];
        prim=P[prim];
    }
    rez++;
    R[rez]=B[prim];
    for ( ; rez; rez-- )
        out<<R[rez]<<" ";
    return 0;
}
