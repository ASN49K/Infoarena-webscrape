#include<iostream>
#include<fstream>
using namespace std; 
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,a[1030][1030],v[1030],x[1030],y[1030],aux,t=0;

void citire()
{
f>>n>>m;
for(i=1;i<=n;i++)
	f>>x[i];
for(j=1;j<=m;j++)
	f>>y[j];

f.close();
}

void functie()
{
for(i=1;i<=n;i++)
	a[i][0]=0;
for(j=1;j<=n;j++)
	a[0][j]=0;
for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		if(x[i]==y[j]){a[i][j]=a[i-1][j-1]+1;}
	else if(a[i-1][j]>=a[i][j-1]){a[i][j]=a[i-1][j];}
		else{a[i][j]=a[i][j-1];}
}


}

void mere()
{       g<<t<<'\n';
		for(i=t;i>=1;i--)
		g<<v[i]<<" ";
		g.close();
}


int afisare(int i,int j)
{
	while(i!=0&&j!=0)
{if(x[i]==y[j]){t++;v[t]=x[i];i--;j--;continue;}
else if(a[i-1][j]>=a[i][j-1])i--;
	else j--;

}
mere();
}


int main()
{citire();
functie();
afisare(n,m);
return 0;
}