#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a,b,A[2000], B[2000], D[2000][2000], sir[2000], nr=0;

int main()
{
    fin>>a>>b;
    for(int i=1; i<=a; i++)
        fin>>A[i];
    for(int i=1; i<=b;i++)
        fin>>B[i];

    for(int i=1; i<=a; i++)
        for(int j=1; j<=b; j++)
            if(A[i]==B[j])
                D[i][j]=1+D[i-1][j-1];
            else
                D[i][j]=max(D[i-1][j], D[i][j-1]);

    for(int i=a, j=b; i;)
    {
        if(A[i]==B[j])
        {
            sir[++nr]=A[i];
            i--;
            j--;
        }
        else
            if(D[i-1][j]<D[j-1][i])
                j--;
            else
                i--;
    }
    fout<<nr<<"\n";

    for(int i=nr; i; i--)
        fout<<sir[i]<<" ";

    return 0;
}
