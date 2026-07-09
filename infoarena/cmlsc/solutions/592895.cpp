#include<fstream>
using namespace std;

unsigned a[1025],b[1025];
int v[1025],p[1025],n,m;


int main()
{
	bool ok;
	int max,maxim=0;
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	
	f>>n>>m;
	for(int i=1;i<=n;i++)
		f>>a[i];
	for(int i=1;i<=m;i++)
		f>>b[i];
	
	if(n>m) max=n;
	else
		max=m;
	
	
	for(int i=1;i<=max;i++)
	{
		if(a[i]==b[i])
		{
			v[i]=maxim+1;
			maxim++;
			p[i]=1;
			continue;
		}
		
		if(a[i]!=b[i])
		{
			 ok=0;
			for(int j=1;j<i;j++)
			{
				if(p[j]==0) 
					if(a[i]==b[j] || b[i]==a[j]) 
					{
						v[i]=maxim+1;
						maxim++;
						p[i]=1;
						p[j]=0;
						ok=1;
					}
			}
			if(ok==0)
				v[i]=maxim;
		}
	}
	g<<maxim<<"\n";
	
	int ultim=1;
	for(int i=1;i<=max;i++)
		if(v[i]==ultim)
		{
			if(n>m) g<<a[i]<<" ";
		    else
				g<<b[i]<<" ";
			ultim++;
		}
}
			
		