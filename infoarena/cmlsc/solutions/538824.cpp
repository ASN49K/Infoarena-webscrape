#include<cstdio>
#define L 1025
using namespace std;

void citeste();
void rezolva();
void afiseaza(int,int);

int a[L],b[L];
int c[L][L], d[L][L];

int na,nb;


void citeste()
{
	freopen("cmlsc.in","r",stdin);
	
	scanf("%d%d",&na,&nb);
	
	for(int i=1;i<=na;i++) scanf("%d",&a[i]);
	
	for(int i=1;i<=nb;i++) scanf("%d",&b[i]);
	
	fclose(stdin);
}

void rezolva()
{
	for(int i=0;i<=na;i++) c[0][i]=0;
    for(int i=1;i<=nb;i++) c[i][0]=0;

 	for(int i=1;i<=na;i++)
		for(int j=1;j<=nb;j++)
		{
			if(a[i]==b[j]) 
			{ 
				c[i][j]=c[i-1][j-1]+1;//daca a[i]==b[j] atunci C(i,j)=C(i-1,j-1)+1
				d[i][j]=1;//memoram in matricea d cazul 1
			}
			else if(c[i-1][j]>c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				d[i][j]=2;//cazul 2
			}
			else 
			{
				c[i][j]=c[i][j-1];
				d[i][j]=3;//cazul 3
			}
	    }
	freopen("cmlsc.out","w",stdout);
	
	printf("%d\n",c[na][nb]);
	
	afiseaza(na,nb);
	
	fclose(stdout);
	
}


void afiseaza(int i, int j)
{	

	if(i>0 &&j>0)
	{
	if(d[i][j]==1)
	{
		afiseaza(i-1,j-1);
		printf("%d ",a[i]);
	}
	else if(d[i][j]==2)
	{
		afiseaza(i-1,j);
	}
	else
	{ 
		afiseaza(i,j-1);
	}
	}
}


int main()
{
	citeste();
	rezolva();
	
	return 0;
}