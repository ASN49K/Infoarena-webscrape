#include<fstream>
using namespace std;
ifstream fin("secv.in");
ofstream fout("secv.out");
int n,i,j,v[100],lung[100],poz[100],maxx,pmax;

int main()
{
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>v[i];
	    lung[i]=1;
	}
	for(i=n-1;i>=1;i--)
		for(j=i+1;j<=n;j++)
			if(v[i]<v[j])
				if(lung[i]<=lung[j])
				{
					lung[i]=lung[j]+1;
					poz[i]=j;
				}
				
for(i=1;i<=n;i++)
  if(lung[i]>maxx)
  {
     maxx=lung[i];
	 pmax=i;
  }
  while(pmax!=0)
  {
	  fout<<v[pmax]<<" ";
	  pmax=poz[pmax];
  }
  return 0;
}
