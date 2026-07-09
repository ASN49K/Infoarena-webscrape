#include<iostream>
#include<fstream>
#define max 1024
using namespace std;
int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	long m,n,i,j,k=0;
	int a[max],b[max];
	f>>m>>n;

	for(i=1;i<=m;i++)
	{
		f>>a[i];
	}
	for(i=1;i<=n;i++)
	{	
		f>>b[i];
	}

	for(i=1;i<=m;i++)
	{
	    for(j=1;j<=n;j++)
	    {
	        if(a[i]==b[j])
		    {
		        k++;
			} 
	    }
	}
	g<<k<<"\n";
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
		{
			if(a[i]==b[j])
			{
			   g<<a[i]<<" ";
			} 
		}
    }
 return 0;
 
}