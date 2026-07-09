#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,n,best[6000001],v[6000001],m,k;
int maxim(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
		f>>v[i];
	
	best[1]=v[1];
	
	for(i=1;i<=n;i++)
		best[i]=maxim(best[i-1]+v[i],v[i]);	
	
	m=best[1];
	for(i=1;i<=n;i++)
		if(best[i]>m)
		{
			m=best[i];
			k=i;
		}	
	int x=k;
	g<<m<<" ";
	while(m>0)
	{
		m=m-v[k];
		k=k-1;
	}
	
	g<<k+1<<" "<<x;
	f.close();
	g.close();
	return 0;
}