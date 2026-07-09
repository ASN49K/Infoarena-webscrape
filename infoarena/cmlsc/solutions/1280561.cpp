#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int a[260],b[260],c[260],m,n,i,j,k=0;

    fstream in("cmlsc.in",ios::in);
    fstream out("cmlsc.out",ios::out);
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(j=1;j<=m;j++)
        in>>b[j];
    in.close();
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                c[k++]=b[j];
    out<<k<<"\n";
    for(i=1;i<=k;i++)
        out<<c[i]<<" ";
    out.close();


    return 0;
}
