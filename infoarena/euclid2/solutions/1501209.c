#include <stdio.h>
#include <stdlib.h>

int T,a,b;

int euclid(int a, int b) {
	int rem = a%b;
	while(rem) {
       a=b;
       b=rem;	   
	}
	return b;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
 
    scanf("%d",&T);
 
    for(int i=0; i<T; i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a,b));
    }
 
    return 0;
}