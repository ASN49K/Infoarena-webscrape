#include <iostream>
#include <cstdio>

using namespace std;

int main ()
{
	freopen ("euclid2.in","r",stdin);
	freopen ("euclid2.out","w",stdout);
	
	int a,b,T,r;
	
	scanf ("%d",&T);//cin >> T;
	for (;T;T--)
	{ 
	  scanf("%d%d", &a,&b);//cin >>a>>b;
	  
	  while(b){r=a%b;a=b;b=r;}
	  printf("%d\n",a);   //cout <<a<<"/n";
		
		
	}
	return 0;
}