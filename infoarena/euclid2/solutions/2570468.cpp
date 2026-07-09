#include <fstream>
using namespace std;
int n,v1[10000],v2[10000], afis[10000];
int main()
{ ifstream f("euclid.in");
ofstream g("euclid.out");
f>>n;
int u=0;
for( int i=1;i<=n;i++)
{ f>>v1[i]>>v2[i];
while(v1[i]!=v2[i])
{ if(v1[i]>v2[i])
v1[i]=v1[i]-v2[i];
else v2[i]=v2[i]-v1[i];
}
afis[i]=v1[i];
}
for(int i=1;i<=n;i++)
g<<afis[i]<<endl;
f.close();
g.close();
    return 0;
}
