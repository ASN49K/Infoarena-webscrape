#include<fstream>
using namespace std;

#define nmax 1024

int M,n,a[nmax],b[nmax],m[nmax][nmax],c[nmax],cont;


int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	
	f>>M>>n;
	
	for(int i=1;i<=M;i++)
		f>>a[i];
	for(int j=1;j<=n;j++)
		f>>b[j];
	
	for(int i=1;i<=M;i++)
		for(int j=1;j<=n;j++)
			if(a[i]==b[j])
				m[i][j]=m[i-1][j-1]+1;
			else
				m[i][j]=max(m[i][j-1],m[i-1][j]);
		
	int i=M,j=n;
	cont=0;
	
	while(i!=0)
		if(a[i]==b[j])
		{
			c[++cont]=a[i];
			i--;
			j--;
		}
		else
			if(m[i-1][j]<m[i][j-1])
				j--;
			else
				i--;
g<<cont<<"\n";

	for(int i=cont;i>=1;i--)
		g<<c[i]<<" ";
	
	return 0;
}
