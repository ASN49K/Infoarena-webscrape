#include<fstream.h>

int s[1025],a[1025],k[1025],poz[1025],max,n,i;
ofstream fout("clmsc.out");
void afisare(int k);
int main()
{	ifstream fin("cmlsc.in");
	fin>>n;
	for(i=1;i<=n;i++)fin>>s[i];
	a[1]=1;poz[1]=0;
	for(i=2;i<=n;i++)
		if(s[i]>s[i-1])
		{       a[i]=a[i-1]+1;poz[i]=i-1;}
		else	a[i]=1;
	max=a[1];
	for(i=2;i<=n;i++)
		if(a[i]>max) max=a[i];
	fout<<max<<'\n';
	for(i=1;i<=n;i++)
		if(a[i]==max)
			afisare(i);
}
void afisare(int k)
{       if(poz[k]==0)
		fout<<s[k]<<' ';
	else
	{	afisare(k-1);
		fout<<s[k]<<' ';
	}
}