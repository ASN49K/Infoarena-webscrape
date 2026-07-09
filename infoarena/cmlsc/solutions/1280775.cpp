#include <iostream>
#include <fstream>
#define nmax 5000
using namespace std;
int main()
{
    int a[nmax],b[nmax],c[nmax],m,n,i,j,k=0;

    fstream in("cmlsc.in",ios::in);
    fstream out("cmlsc.out",ios::out);
    in>>n>>m;
    for(i=0;i<n;i++)
        in>>a[i];
    for(j=0;j<m;j++)
        in>>b[j];
    in.close();
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(a[i]==b[j])
                c[k++]=b[j];
    out<<k<<"\n";
    for(i=0;i<k;i++)
        out<<c[i]<<" ";
    out.close();


    return 0;
}
