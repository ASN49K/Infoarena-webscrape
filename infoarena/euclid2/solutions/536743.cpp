#include<stdio.h> 
int T,a,b,i; 
 
 int euclid(int x, int y) 
{   int r; 
	while(y) {r=x%y; x=y; y=r;} 
    return x; 
} 
 
 int main() 
{   freopen ("euclid2.in", "r", stdin); 
	freopen ("euclid2.out", "w", stdout); 
     
	scanf("%d",&T); 
    for(i=1; i<=T; ++i)     
	{   scanf ("%d%d",&a,&b); 
       printf ("%d\n",euclid(a,b));     
	} 
    return 0; 
}
