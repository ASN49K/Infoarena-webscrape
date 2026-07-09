#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{  int n,m,j,k=0,i,a[10],b[20];
    f>>n>>m;
    for(i=1;i<=n;i++)
    f>>a[i];
    for(i=1;i<=n;i++)
    f>>b[i];

    for(i=1;i<=n;i++)
    for(j=1;j<n;j++)
        if(a[i]==b[j])
        {
            k++;
        }
            g<<k<<endl;

    for(i=1;i<=n;i++)
    for(j=1;j<n;j++)
        if(a[i]==b[j])
        {
            g<<a[i]<<" ";
        }

    return 0;
}
