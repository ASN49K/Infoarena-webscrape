#include<fstream.h>
#include<iostream.h>
long x[200000],y[200000],n;
ifstream f("euclid2.in");
ofstream g("euclid2.out ");
void cit()
{f>>n;
for(int i=0;i<n;i++)
	{f>>x[i];
	 f>>y[i];
	}
}

int cmmdc(int i)
	{while(x[i]!=y[i])
		if(x[i]<y[i])y[i]=y[i]-x[i];
	else
		x[i]=x[i]-y[i];
return x[i];	}
int main()
{cit();
for(int i=0;i<n;i++)
	g<<cmmdc(i)<<endl;
f.close();
g.close();
}
