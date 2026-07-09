#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define maxim(a,b) ((a>b) ? a:b)
using namespace std;

int n,m,A[1024],B[1024],i,j,D[1024][1024],index,Sir[1024];

int main()
{
    fstream fin ("cmlsc.in");
    fstream fout("cmlsc.out");
    fin>>n>>m;

    FOR(i,1,n) fin>>A[i];
    FOR(i,1,m) fin>>B[i];

    FOR(i,1,n)
        FOR(j,1,m)
        {
            if(A[i] == B[j])
                D[i][j] = D[i-1][j-1] + 1;
            else
                D[i][j] = maxim(D[i-1][j],D[i][j-1]);
        }
    while(i!=0 || j!=0)
    {
        if(A[n-i+1]==B[m-j+1])
            {
                Sir[index++] = A[n-i+1];
                i--;j--;
            }
        else if(D[i-1][j] < D[i][j-1])
            j--;
        else i--;

    }
    FOR(i,1,index-1) fout<<Sir[i]<<" ";
    fin.close();
    fout.close();
    return 0;
}
