#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1026],b[1026],c[1026][1026],i,j,n,m,x,v[1026];
int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
   f>>n>>m;
   for(i=1;i<=n;i++)
    f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
g<<c[n][m]<<'\n';
    x=c[n][m];
    for(i=n;i>=2&&c[n][m]>0;i--)
        for(j=m;j>=2&&c[n][m]>0;j--)
            if(c[i][j]==c[i-1][j-1]+1){
                v[c[n][m]]=a[i];
                c[n][m]--;}
        for(i=1;i<=x;i++)
            g<<v[i]<<" ";
    return 0;
}
