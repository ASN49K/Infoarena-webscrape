#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int m,n,i,j,a[1024],b[1024],o=0;
    fstream f("cmlsc.in",ios::in);
    fstream g("cmlsc.out",ios::out);
    f>>m>>n;
    for(i=0;i<m;i++) f>>a[i];
    for(j=0;j<n;j++)
    {
        f>>b[j];
        for(i=0;i<m;i++) if(a[i]==b[j]) o++;
    }
    g<<o<<endl;
    for(j=0;j<n;j++)
    {
        f>>b[j];
        for(i=0;i<m;i++) if(a[i]==b[j]) g<<b[j]<<" ";
    }
    f.close();
    g.close();
    return 0;
}
