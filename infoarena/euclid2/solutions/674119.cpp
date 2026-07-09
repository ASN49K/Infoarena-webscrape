#include<stdio.h> 
int T,a,b; 
int d(int a, int b) 
{
	if(b==0)return a;
	return d(b, a%b); 
} 
int main() 
{ 	
	freopen("euclid2.in","r",stdin); 
	freopen("euclid2.out","w",stdout);
	scanf("%d", &T); 
	for(int i=1;i<=T;i++) 
	{    
		scanf("%d %d", &a, &b);
		printf("%d\n", d(a,b));     
	}   
	return 0; 
}