#include <iostream>
#include <fstream>
#define NM 1026

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[NM],B[NM],n,m;
short lcs[NM][NM];

void determinare(int i,int j)
{
    if(lcs[i][j]==0) return;
    if(A[i]==B[j])
    {
        determinare(i-1,j-1);
        fout<<A[i]<<" ";
    }
    else if(lcs[i][j]==lcs[i-1][j]) determinare(i-1,j);
    else determinare(i,j-1);
}

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; ++i) fin>>A[i];
    for(int i=1; i<=m; ++i) fin>>B[i];
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(A[i]==B[j]) lcs[i][j]= 1 + lcs[i-1][j-1];
                else lcs[i][j]= max(lcs[i-1][j], lcs[i][j-1]);

    /*for(int j=1; j<=m; ++j)
    {
        for(int i=1; i<=n; ++i) cout<<lcs[i][j]<<" ";
        cout<<"\n";
    }*/

    fout<<lcs[n][m]<<"\n";
    determinare(n,m);

    fin.close(); fout.close();
    return 0;
}
