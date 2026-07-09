	#include<fstream>
	//#include<iostream>
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
	int a[1025],b[1025],n,m,i,j,c[1025][1025],v[1025],p=1;
	cin>>n>>m;
	for(i=1;i<=n;++i) cin>>a[i];
	for(j=1;j<=m;++j) cin>>b[j];
	
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if( a[i] == b[j] ){
				c[i][j]=c[i-1][j-1]+1;
				//v[p]=a[i];
				//p++;
				}
			else
			c[i][j]=max(c[i][j-1],c[i-1][j]);
			
	cout<<c[n][m]<<endl;
	//for(i=1;i<p;++i)  cout<<v[i]<<" ";
	i=n; j=m;
	while( j!=0 && i!=0){
		if(a[i] == b[j])
		{
			v[p]=a[i];
			i--;j--;p++;
		}
		else if( c[i-1][j]>c[i][j-1]) i--;
		else j--;
	}
	p--;
	for(i=p;i>=1;--i) cout<<v[i]<<" ";
	cout<<endl;
	
	return 0;
}
