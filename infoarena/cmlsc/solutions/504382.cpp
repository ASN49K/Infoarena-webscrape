#include<iostream>
#include<fstream>
using namespace std; 
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
long long n,m,i,j,a[1025][1025],b[1025][1025],x[1025],y[1025],aux;

void citire()
{
f>>n>>m;
if(n>m)
{
for(i=1;i<=n;i++)
	f>>x[i];
for(j=1;j<=m;j++)
	f>>y[j];
}
else
{aux=n;n=m;m=aux;
for(i=1;i<=n;i++)
	f>>x[i];
for(j=1;j<=m;j++)
	f>>y[j];
}	
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
		if(x[i]==y[j]){a[i][j]=a[i-1][j-1]+1;b[i][j]=1;}
	else if(a[i-1][j]>=a[i][j-1]){a[i][j]=a[i-1][j];b[i][j]=2;}
		else{a[i][j]=a[i][j-1];b[i][j]=3;}
}


}

//void mere()
//{
//	g<<a[n][m]<<'\n';
	//for(i=1;i<=n;i++)
		//if(v[i]!=0)g<<v[i]<<" ";
		
//}


int afisare(int i,int j)
{
	if(i!=0&&j!=0)
{if(b[i][j]==1){afisare(i-1, j-1);g<<x[i]<<" ";}
else if(b[i][j]==2)afisare(i-1,j);
	else afisare(i,j-1);


}
//return 0;

}


int main()
{citire();
functie();
g<<a[n][m]<<'\n';
afisare(n,m);
//mere();

}