#include <stdio.h>

FILE *f,*s;
int n,k,i,x,v[32],v2[32];
long long sum;

int gcb(int x, int y)
{
	if (!y)  return x;
	return gcb(y, x % y);
}

void combinari(int p)  
{  
    int j, q, b, r;
    for (j=v2[p-1]+1;j<=k;++j)  
    {  
        v2[p]=j;  
  
        if (p==i)  
        {
			x=v[v2[1]];
			for (q=2;q<=i;q++ && x > 1)		
				x = gcb(x, v[v2[q]]);
			
			if(i%2==0)
				sum -= (long long)(((long long)(n/x)*(n/x+1))/2)*x;
			else
				sum += (long long)(((long long)(n/x)*(n/x+1))/2)*x;
	}	
        else combinari(p+1);  
    }  
  
}  

int main()
{
	f=fopen("suman.in","r");
	s=fopen("suman.out","w");
	
	fscanf(f,"%d %d",&n,&k);
	
	for(i=1;i<=k;++i) fscanf(f,"%d",&v[i]);
	
	for(i=1;i<=k;++i) combinari(1);
	
	fprintf(s,"%lld",sum);
	
	fclose(s);
	
	return 0;
}		