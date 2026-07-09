#include<fstream.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
void citeste_vectori(int& n,int& m,int a[],int b[])
{
	int i,j;
	
	f>>n;
	f>>m;
	for(i=0;i<n;i++)
		f>>a[i];
	for(j=0;j<m;j++)
		f>>b[j];
}
void cmlsc(int n,int m,int a[],int b[])
{
	int i,j,r=0,c[1204],d=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i]==b[j])
			{
				c[r]=a[i];
				r++;
			
			}
		}
	}
    g<<r<<"\n";
	d=r;
	for(r=0;r<d;r++)
	g<<c[r]<<" ";	
	
	
}

int main()
{
	int n,m,a[1204],b[1204];
	citeste_vectori(n,m,a,b);
	cmlsc(n,m,a,b);
}	

	
		