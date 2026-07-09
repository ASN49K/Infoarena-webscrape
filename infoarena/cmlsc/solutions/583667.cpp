#include <fstream>

using namespace std;
fstream f("cmlsc.in",ios::in),g("cmlsc.out",ios::out);

short a[1025],b[1025];
short n,m;
short maxs[1025];
short drum[1025];

void afiseaza(short k);

int main()
{
	short max,k;
	f>>n>>m;
	for(int i=1;i<=n;i++)
		f>>a[i];
	for(int i=1;i<=m;i++)
		f>>b[i];
	k=0;
	max=0;
	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(a[j]==b[i])
			{
				if(j>k){
				maxs[j]= ++maxs[k];
				if(maxs[j]>max)
				{
					max=maxs[j];
					drum[j]=k;
					k=j;
				}
			}
			}
		}
		g<<max<<'\n';
		afiseaza(k);
		return 0;
}

void afiseaza(short k)
{
	if(k==0)
	   return;
	else
	{
		afiseaza(drum[k]);
		g<<a[k]<<' ';
	}
}
					
				
				
			