#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n,m,x,a[1024],b[1024],d[1024][1024],s[1024],c,l;
int main()
{
    fin >> n >> m;
    for(int i=1;i<=n;++i)
    {
        fin >> a[i];
    }
    for(int i=1;i<=m;++i)
    {
        fin >> b[i];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    int i = n, j = m;
    while(i)
    {
        if(a[i]==b[j])
        {
            s[c++]= a[i];
            --i;
            --j;
        }
        else if(d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;
    }
    fout << c << '\n';
    for(int i=0;i<c;++i)
        fout << s[i] << " ";
    return 0;
}
