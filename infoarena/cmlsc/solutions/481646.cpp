
#include<cstdio>
#include<fstream>
#include<vector>


using namespace std;

#define nn 1025

int n,m,vn[nn],vm[nn];

int main ()
{

ifstream in ("cmlsc.in");
freopen("cmlsc.out","w",stdout);

in>>n>>m;
for(int i=1;i<=n;++i)
in>>vn[i];
for(int i=1;i<=m;++i)
in>>vm[i];
in.close();
vector<int> v(0);
for(int i=1;i<=n;++i)
for(int j=1;j<=m;++j)
if(vn[i]==vm[j]){
v.push_back(vn[i]);
j=m;
}

printf("%d\n",v.size());
for(int i=0;i<v.size();++i)
printf("%d ",v[i]);

return 0;}
