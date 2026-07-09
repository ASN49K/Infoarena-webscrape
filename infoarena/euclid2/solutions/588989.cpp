#include<fstream>
using namespace std; 
int n,i,a,b,r; 
int main(void) 
{ 
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for(i=1;i<=n;i++)
{	f>>a>>b;
do
{r=b%a;
b=a;
a=r;
}while(r!=0);
g<<b<<endl;	
}
return 0;
}