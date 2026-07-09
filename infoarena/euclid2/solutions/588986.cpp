#include<fstream>
using namespace std; 
int n,i,a,b; 
int main(void) 
{ 
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for(i=1;i<=n;i++)
{	f>>a>>b;
while(a!=b)
	if(a<b)
		b=b-a;
	else 
		a=a-b;
g<<a<<endl;	
}
return 0;
}