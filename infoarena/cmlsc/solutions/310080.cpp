#include<stdio.h>
struct sir{int nr;
	   sir *adr;} ;
int n,m,i,j,k,c;
sir *a,*l,*a1,*l1;

int main()
{ sir *p,*q;

freopen ("cmlsc.in","r",stdin) ;
freopen ("cmlsc.out","w",stdout);
scanf ("%d %d",&n ,&m);
a=NULL;
l=NULL;
for(i=1;i<=n;i++)
	{p=new sir;
	 scanf("%d",&c);
	 p->nr=c;
	 p->adr=NULL;
	 if(a==NULL)
		a=a1=p;
	 else
		{a1->adr=p;
		 a1=p;}}
for(i=1;i<=m;i++)
	{scanf("%d",&c);
	 p=a;
	 while(p)
	    {if(c==p->nr)
		{q=new sir;
		q->nr=p->nr;
		q->adr=NULL;
		k++;
		if(l==NULL)
			l=l1=p;
		else
			{l1->adr=q;
			l1=q;}

			}
	      p=p->adr;}

		}
printf("%d\n",k);

p=l;
while(p)
	{printf("%d ",p->nr);
	p=p->adr;}

return 0;
}