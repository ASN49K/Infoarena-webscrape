#include<fstream.h>
#include<iostream.h>
int main()
{int v[100],v1[100],i,n,m,lungv,lungmax=0,lung,aux=0;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>n;
f>>m;
for(i=0;i<n;i++)
	f>>v[i];
for(i=0;i<m;i++)
	f>>v1[i];
for(i=0;i<n;i++)
	while(aux<m)
	 if(v[i]==v1[aux])
	 {lungv=i;
	  lung++;
	  aux++;
	 }
	else
	{if(lung>lungmax)
		 lungmax=lung;
	 lung=0;
	}
	g<<lung<<endl;
for(i=lungv;i<lungv+lung;i++)
	g<<v[i];
return 0;
}
	
