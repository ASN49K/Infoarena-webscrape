#include<fstream>
using namespace std; 
ifstream f("euclid2.in");
ofstream  out("euclid2.out");
int dive(int a,int b)
{ 
	while(a!=b) 
	{ 
		if(a>b)
		a=a-b;  
		else
       b=b-a; 
	} 
return a; 
}		 
int main ()
{
	int n,i; 
	long a,b;
	f>>n; 
	 for(i=1;i<=n;i++) 
	{ 	 f>>a>>b;  
	  out<<dive(a,b)<<'\n';
	} 
}
     