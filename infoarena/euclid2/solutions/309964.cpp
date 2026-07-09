#include<fstream.h>
#include<iostream.h>
int a,b,n;

int euclid(int a, int b)  
  {
   int c;  
   while (b) {  
       c = a % b;  
       a = b;  
       b = c;  
   }  
   return a;  
}
int main()
{
ifstream f("euclid2.in") ;
ofstream g("euclid2.out");
f>>n;
for(int i=1;i<=n;i++)
{f>>a>>b;
if(a>=b)
	{g<<euclid(a,b);g<<endl;}
else
    if(a<b)
       {	g<<euclid(b,a);g<<endl;}
	 }

g.close();
return 0;
}