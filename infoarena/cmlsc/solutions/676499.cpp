#include<fstream>
#define Nmax 1024
using namespace std;

ifstream g("cmlsc.in");
ofstream t("cmlsc.out");

int xmat[Nmax][Nmax],x1[Nmax],x2[Nmax],x[Nmax];
int n1,n2,mat,i,j;

int maxim(int a,int b)
{if(a>b)
	return a;
else 
	return b;
}

int main()
{
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
t<<mat<<"\n";
for(i=mat;i>0;i--)
	t<<x[i]<<" ";
g.close();
t.close();
return 0;}
