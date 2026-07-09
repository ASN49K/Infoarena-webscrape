#include <stdio.h>

FILE *f,*s;

int main()
{
	f=fopen("nim.in","r");
	s=fopen("nim.out","w");
	
    int t,n,x,i;
	
	fscanf(f,"%d",&t);
	
    for (int i=1; i<=t; i++)
    {
		fscanf(f,"%d",&n);
        
        int xr=0;
		
        for (int j=1; j<=n; j++)
        {
			fscanf(f,"%d",&x);
            
            xr=xr^x;
        }
		
		if (xr==0) 
			fprintf(s,"NU\n");
		else 
			fprintf(s,"DA\n");
    }
    
	fclose(s);
	
    return 0;
}