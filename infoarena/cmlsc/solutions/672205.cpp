#include<iostream>
#include<fstream>
using namespace std;
int main()
{ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,i,j,k,v[1025][1025];
char a[1024],b[1024],c[1024];
f>>m;
f>>n;
k=0;
for(i=1;i<=m;i++)
	f>>a[i];
for(i=1;i<=n;i++)
	f>>b[i];
for(i=0;i<=m;i++)
	for(j=0;j<=n;j++)
		v[i][j]=0;
for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
		if(a[i]==b[j])
			v[i][j]=v[i-1][j-1]+1;
		else
			if(v[i-1][j]>v[i][j-1])
					v[i][j]=v[i-1][j];
			else 
				if(v[i][j-1]>=v[i-1][j])
					v[i][j]=v[i][j-1];
i=m;
j=n;
while(i>0&&j>0)
	if(v[i][j]==v[i-1][j])
		i--;
	else 
		if(v[i][j]==v[i][j-1])
			j--;
		else {k++;
			  c[k]=a[i];
			  i--;
			  j--;	
			    }
g<<k<<endl;		
for(i=k;i>=1;i--)
	g<<c[i]<<" ";
f.close();
g.close();
}