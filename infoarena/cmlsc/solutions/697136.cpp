#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int x[300],y[300],z[300],t[300];
int main()
{int n,m,i,j,p,lmax=0,k;
f>>n>>m;
for(i=1;i<=n;i++)
	f>>x[i];
for(i=1;i<=m;i++)
	f>>y[i];
p=1;
k=0;
for(i=1;i<=n;i++)
	{
	 for(j=p;j<=m;j++)
		if(x[i]==y[j])
			{k++;
			 z[k]=x[i];
			 p=j+1;
			}
	 if(k>lmax)
		{lmax=k;
		 for(j=1;j<=lmax;j++)
			 t[j]=z[j];
		}
	}
cout<<lmax<<endl;
for(i=1;i<=lmax;i++)
	cout<<t[i]<<" ";
return 0;
}