#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025], b[1025],m,n,nr,lcs[1025],k;
int main()
{
    fin>>m>>n;
    for(int i=1;i<=m;i++) fin>>a[i];
    for(int i=1;i<=n;i++) fin>>b[i];

    k=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=k;j<=m;j++)
            if(b[i]==a[j])
            {
                lcs[++nr]=b[i];
                k=j;
                break;
            }
    }
    fout<<nr<<'\n';
    for(int i=1;i<=nr;i++) fout<<lcs[i]<<" ";

    return 0;
}
