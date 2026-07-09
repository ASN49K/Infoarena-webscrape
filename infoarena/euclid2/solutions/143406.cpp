#include<stdio.h>
int main()
{
	long a,b,r;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%ld",&a);
    scanf("%ld",&b);
    while(a%b!=0)
    	{
        	r=a%b;
            a=b;
            b=r;
        }
        printf("%ld",b) ;
}