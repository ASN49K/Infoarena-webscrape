
#include<cstdio>
#include<fstream>
#include<vector>


using namespace std;

#define nn 1025

int vn[nn],vm[nn],mat[nn][nn];
int n,m;

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
if (vn[i] == vm[j])
mat[i][j] = 1 + mat[i-1][j-1];
else
mat[i][j] = ((mat[i-1][j]>mat[i][j-1])?mat[i-1][j]:mat[i][j-1]);

for(int i=n,j=m;i;)
if (vn[i] == vm[j]){
v.push_back(vn[i]);
--i;
--j;
}
else if (mat[i-1][j] < mat[i][j-1])
--j;
else
--i;

printf("%d\n",v.size());
for(int i=v.size()-1;i>=0;--i)
printf("%d ",v[i]);

return 0;}
