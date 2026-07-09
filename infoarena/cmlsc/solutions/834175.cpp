#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
int v[1024],s=0,n,m;
f>>n; f>>m;
int v1[n],v2[m];
//v1=new (nothrow) int[n];
//v2=new (nothrow) int[m];

for(int i=0;i<n;i++)
f>>v1[i];
for(int i=0;i<m;i++)
f>>v2[i];

for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        if(v1[i]==v2[j])
            v[s++]=v1[i];
g<<s<<"\n";
for(int i=0;i<s;i++)
g<<v[i]<<" ";
}
