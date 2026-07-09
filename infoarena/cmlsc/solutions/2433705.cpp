#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f ("cmlsc.in");
    ofstream g ("cmlsc.out");
    int m,n,i,j,k=0;
    f>>m>>n;
    int a[m],b[n],c[1024];
    for(i=0;i<m;i++)
        f>>a[i];
    for(j = 0;j < n;j++)
        f>>b[j];
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            if(a[i] == b[j]) c[k++]=a[i];

    g<<k<<endl;
    for(i=0;i < k; i++)
        g<<c[i]<<" ";
    return 0;
}
