#include <fstream>
using namespace std;
int n,v1[10000],v2[10000], afis [10000];
ifstream f("euclid.in");
ofstream g("euclid.out");
int main()
{ cin>>n;
for( int i=1;i<=n;i++)
{ f>>v1[i]>>v2[i];
while(v1[i]!=v2[i])
{ if(v1[i]>v2[i])
v1[i]=v1[i]-v2[i];
else v2[i]=v2[i]-v1[i];
}
g<<v1[i]<<endl;
}
    return 0;
}
