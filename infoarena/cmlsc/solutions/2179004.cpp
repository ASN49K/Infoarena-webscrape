#include <bits/stdc++.h>
#define nm 1024
#define For(i,a,b) for(i=a;i<=b;i++)
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a,b,ab[nm][nm], sol[nm], va[nm], vb[nm];
int main()
{
    fin>>a>>b;
    int i,j, nr=-1;
    For(i,1,a) fin>>va[i];
    For(i,1,b) fin>>vb[i];
    For(i,1,a)
    For(j,1,b)
    if(va[i]==vb[j]) ab[i][j]=1+ab[i-1][j-1];
    else ab[i][j]=max(ab[i-1][j],ab[i][j-1]);
    for(i=a;j=b;i)
        if(va[i]==vb[j]) sol[++nr]=va[i],i--,j--;
        else if(ab[i-1][j]>ab[i][j-1]) i--;
        else j--;
    fout<<nr+1<<"\n";
    for(;nr;nr--)
        fout<<sol[nr]<<" ";

}
