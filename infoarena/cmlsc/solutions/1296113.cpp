#include <iostream>
#include <cstring>
#include <fstream>
#define NMAX 10000
#define maxim(a,b) ((a>b)? a:b)
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int c[NMAX][NMAX],i,j,n,m;
char A[NMAX],B[NMAX],sir[NMAX];

int main()
{
    fin>>(A+1);
    fin>>(B+1);
    n=strlen(A+1);
    m=strlen(B+1);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;j++)
        {
            if(A[i]==B[j])
            c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]=maxim(c[i-1][j],c[i][j-1]);
        }
        j=i=c[n][m];

    while(n && m!=0)
    {
        if(A[n]==B[m])
            {sir[i--]=A[n];
            n--;
            m--;
            }
        else if(c[n][m-1]>c[n-1][m])
            m--;
        else n--;
    }
    for(i=1;i<=j;++i)
        fout<<sir[i];
}
