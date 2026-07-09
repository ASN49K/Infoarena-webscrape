#include<fstream>
using namespace std;
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int main()
{
	int a[2000],b[2000],n,m,i,j,c[2000][2000],v[2000],p=1;
	cin>>n>>m;
	for(i=1;i<=n;++i) cin>>a[i];
	for(j=1;j<=m;++j) cin>>b[j];
	
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if( a[i] == b[j] ){
				c[i][j]=c[i-1][j-1]+1;
				v[p]=a[i];
				p++;
				}
			else
			c[i][j]=max(c[i][j-1],c[i-1][j]);
			
	cout<<c[n][m]<<endl;
	
	for(i=1;i<p;++i) 
		cout<<v[i]<<" ";
	cout<<endl;
	
	return 0;
}
