#include<stdio.h>
FILE *in,*out;
int a,b,t;

int gcd(int u, int v){
    if(u == v)
        return v;
    if(!u)
        return v;
    if(!v)
        return u;
    if(!(u%2)){ // if u is even
        if(!(v%2)) // if u and v are even
            return (2*gcd(u>>1, v>>1));
        else // u is even and v is odd
            return  gcd(u>>1, v);
    }
    else if(!(v%2)) // if u is odd and v is even
        return gcd(u, v>>1);
    else{ // both are odd
        if(u>=v)
            return gcd((u-v)>>1, v);
        else
            return gcd((v-u)>>1, u);
    }
}

int main()
{
	in=fopen("euclid2.in","rt");
	out=fopen("euclid2.out","wt");
	fscanf(in,"%d",&t);
	for(int i=1;i<=t;i++)
	{
		fscanf(in,"%d %d",&a,&b);
		
		fprintf(out,"%d\n",gcd(a,b));
	}	
	
	return 0;
}