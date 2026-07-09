#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int nr=0,i,j,n,m,*a,*b,*c;
    f>>n>>m;
    a=(int*)malloc(n*sizeof(int));
    b=(int*)malloc(m*sizeof(int));
    if (n>m) c=(int*)malloc(m*sizeof(int));
        else c=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++) f>>a[i];
    for (i=0;i<m;i++) f>>b[i];
    for (i=0;i<n;i++)
        for (j=0;j<m;j++) if (a[i]==b[j]) {
            c[nr++]=a[i];
            break;
    }
    g<<nr<<endl;
    for (i=0;i<nr;i++) g<<c[i]<<" ";
    f.close();
    g.close();
    return 0;
}
