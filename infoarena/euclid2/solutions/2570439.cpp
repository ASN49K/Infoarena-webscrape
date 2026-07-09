#include <fstream>
using namespace std;
int n,v1[10000],v2[10000], afis [10000];
ifstream cin("euclid.in");
ofstream cout("euclid.out");
int main()
{ cin>>n;
for( int i=1;i<=n;i++)
{ cin>>v1[i]>>v2[i];
while(v1[i]!=v2[i])
{ if(v1[i]>v2[i])
v1[i]=v1[i]-v2[i];
else v2[i]=v2[i]-v1[i];
}
cout<<v1[i];
}
    return 0;
}
