#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int i,j,n,m,a[99],b[99],k=0;
    fin>>n>>m;
    for(i=1;i<=n;++i)
        fin>>a[i];
    for(j=1;j<=m;++j)
        fin>>b[j];
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    if(a[i]==b[j])
    fout<<a[i]<<" ";
    fin.close();
    fout.close();
    return 0;
}
