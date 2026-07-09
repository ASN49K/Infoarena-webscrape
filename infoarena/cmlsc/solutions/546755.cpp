#include<fstream>
#define max 257
using namespace std;
int i,j,m,n,v[max][max],t,a[max],b[max],rez[max];

ifstream f("cmlsc.in");
ofstream o("cmlsc.out");

void reconstituie(int m, int n)
{
	if (v[m-1][n]||v[m][n-1])
	{
		if (v[m-1][n]<v[m][n]&&v[m][n-1]<v[m][n])
			rez[t++]=a[m];
		if (v[m-1][n]>v[m][n-1])
			reconstituie(m-1, n);
		else
			reconstituie(m, n-1);
	}
	else
		rez[t]=a[m];
}

void tipareste() 
{      
for (i=t;i>=0;i--) 
	o<<rez[i];  
}
int main ()
{
	f>>n>>m;
	for (i=1;i<=n;i++)
		f>>a[i];
	for (j=1;j<=m;j++)
		f>>b[j];
	for (i=1;i<=n;i++)
		for (j=0;j<=m;j++)
			if (a[i]==b[j])
				v[i][j]=1+v[i-1][j-1];
			else
				if (v[i-1][j]>v[i][j-1])
					v[i][j]=v[i-1][j];
				else
					v[i][j]=v[i][j-1];
	o<<v[n][m]<<"\n";
	reconstituie(m,n);
	tipareste();
	return 0;
}
