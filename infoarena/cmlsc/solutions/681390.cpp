#include<iostream>
#include<fstream>
using namespace std;
int n,a[50],b[50],m;
ifstream f("cmlsc.in");
void cit(){
f>>n>>m;
for(int i=1;i<=n;i++)
	f>>a[i];
for(int i=1;i<=m;i++)
	f>>b[i];
f.close();
}
int prog(int b[], int a[]){
	int c[50][50],i,j;
	for(i=1;i<=m;i++)
		c[i][0]=0;
	for(j=1;j<=n;j++)
		c[0][j]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else c[i][j]=max(c[i][j-1],c[i-1][j]);
	return c[m][n];
}
int main(){
	cit();
	ofstream g("cmlsc.out");
	g<<prog(a,b);
	g.close();
}