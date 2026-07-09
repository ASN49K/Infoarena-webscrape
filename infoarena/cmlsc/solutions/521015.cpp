#include<stdio.h>
int c[1024];

int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	int m,n,a[1024],b[1024],i,j,max=257,cont,start=0,max_cont=0,max_st=0;   // contor = lungime subsir , max = val curent max ,

	scanf("%d",&n);                                              // start = poz inceput subsir
	scanf("%d",&m);
	
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	
	for(i=0;i<m;++i)
		scanf("%d",&b[i]);
	
	for(i=0;i<1024;++i)
		c[i]=-1;
	
	if(n>=m)
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
			if(a[i]==b[j])
			{
				c[i]=j;
				j=m;
			}
	}
	else
		for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
			if(b[i]==a[j])
			{
				c[i]=j;
				j=n;
			}
	}
	if(n>=m)
	{
		for(i=0;i<n;++i)
			if( c[i]>=0 && c[i]<=max )
			{
				max=c[i];
				cont=1;
				start=i;
				for(j=i+1;j<n;++j)
					if(c[j]>max)
					{
						cont++;
						max=c[j];
					}
				if(cont>max_cont)
				{
					max_st=start;
					max_cont=cont;
				}
			}
			printf("%d\n%d ",max_cont,a[max_st]);    
			max=c[max_st];
			for(i=max_st+1;i<n;++i)
				if(c[i]>max)
				{
					printf("%d ",a[i]);
					max=c[i];
				}
	}
	else
	{
		for(i=0;i<m;++i)
			if( c[i]>=0 && c[i]<=max )
			{
				max=c[i];
				cont=1;
				start=i;
				for(j=i+1;j<m;++j)
					if(c[j]>max)
					{
						cont++;
						max=c[j];
					}
				if(cont>max_cont)
				{
					max_st=start;
					max_cont=cont;
				}
			}
		printf("%d\n%d ",max_cont,b[max_st]);    
			max=c[max_st];
			for(i=max_st+1;i<m;++i)
				if(c[i]>max)
				{
					printf("%d ",b[i]);
					max=c[i];
				}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
