#include<fstream.h>
#include<iostream.h>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
struct nod
	{
		int info1, info2;
		
	};
	nod a[100000];
int n,k,f,x[100000];
/*void cit()
{
	int i,j;
	fin>>n;
	while(fin>>i>>j)
	{
		k++;
		if(i>=j)
		{
			a[k].info1=i;
			a[k].info2=j;
		}
		else
		{
			a[k].info1=j;
			a[k].info2=i;
		}
		
	}
}*/
void cmmdc()
{
	int i,j,g;
	for(i=1;i<=n;i++)
		if(a[i].info1%a[i].info2==0)
		{
			f++;
			x[f]=a[i].info2;
		}
		else
			
		{
			j=a[i].info2/2;
			g=0;
			while(j>=1 && g==0)
			{
				if(a[i].info2%j==0 && a[i].info1%j==0)
				{
					f++;
					x[f]=j;
					g=1;
				}
				j--;
			}
		}
}
int main()
{
	int i,j;
	fin>>n;
	while(fin>>i>>j)
	{
		k++;
		if(i>=j)
		{
			a[k].info1=i;
			a[k].info2=j;
		}
		else
		{
			a[k].info1=j;
			a[k].info2=i;
		}
		
	}

	cmmdc();
	for(i=1;i<=f;i++)
		fout<<x[i]<<'\n';
	return 0;
}
	