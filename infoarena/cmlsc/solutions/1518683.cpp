#include<iostream>
#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1025],b[1025],c[1025][1025],m,n,v[1025],k;
int main(){
	int i,j;
	in>>n>>m;
	for(i=1;i<=n;i++)in>>a[i];
	for(j=1;j<=m;j++)in>>b[j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
		else
			if(c[i-1][j]>=c[i][j-1])
				c[i][j]=c[i-1][j];
			else
				c[i][j]=c[i][j-1];
			out<<c[n][m]<<'\n';
			i=n;
			j=m;
			k=c[n][m];
			while(i && j){
	if(a[i]==b[j]){
		v[k--]=a[i];
		i--;
		j--;
	}
	else
		if(c[i-1][j]>=c[i][j-1])
			i--;
		else
			j--;
			}
			k=c[n][m];
			for(i=1;i<=k;i++)
				out<<v[i]<<" ";
			return 0;
}
