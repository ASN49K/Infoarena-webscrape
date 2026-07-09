#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,j,m,n,a[256],b[256],k;
int main()
{f>>m>>n;
for(i=0;i<m;i++)
    f>>a[i];
for(i=0;i<n;i++)
    f>>b[i];
for(i=0;i<m;i++)

    for(j=0;j<n;j++)
    if(a[i]==b[j])
        g<<b[j]<<" ";

    return 0;
}
