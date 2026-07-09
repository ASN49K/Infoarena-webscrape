#include<iostream>
#include<fstream>
//#include<time.h>
using namespace std;

int xmat[1024][1024];

int maxim(int a,int b)
{if(a>b)
	return a;
else 
	return b;
}

int main()
{int n1,n2,mat,i,j,x1[1024],x2[1024],x[1024];
//int t1,t2;
//t1=clock();
ifstream g("cmlsc.in");
g>>n1>>n2;  
for(i=1;i<=n1;i++)
	g>>x1[i];
for(i=1;i<=n2;i++)
	g>>x2[i];
for(i=1;i<=n1;i++)
	for(j=1;j<=n2;j++)
		if(x1[i]==x2[j])
			xmat[i][j]=1+xmat[i-1][j-1];
	    else
			xmat[i][j]=maxim(xmat[i-1][j],xmat[i][j-1]);
i=n1; j=n2; mat=0;
while((i>0)&&(j>0))
      {if(x1[i]==x2[j])
        {mat++;
		x[mat]=x1[i];
		i--;
		j--;}
	  else
		  if(xmat[i-1][j]<xmat[i][j-1])
			  j--;
		  else
			  i--;
	  }
ofstream t("cmlsc.out");
for(i=1;i<=n1;i++)
	{for(j=1;j<=n2;j++)
		cout<<xmat[i][j]<<" ";
	cout<<endl;}
t<<mat<<"\n";
for(i=mat;i>0;i--)
	t<<x[i]<<" ";
g.close();
t.close();
//t2=clock();
//cout<<(double)(t2-t1)/CLOCKS_PER_SEC;
return 0;}
