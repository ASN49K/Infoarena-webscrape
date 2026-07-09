#include<fstream>
int v[1024];
using namespace std;
int main()
{
int n,m,a[257],b[257],i,maxim=0;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
in>>n>>m;
for(i=1;i<=n;i++){in>>a[i];v[a[i]]++;if(a[i]>maxim) maxim=a[i];}
for(i=1;i<=m;i++){in>>b[i];v[b[i]]++;if(b[i]>maxim) maxim=b[i];}
int k=0;
for(i=1;i<=maxim;i++)if(v[i]==2) k++;
out<<k<<'\n';
for(i=1;i<=maxim;i++)if(v[i]==2) out<<i<<" ";
in.close();
out.close();
return 0;
}
