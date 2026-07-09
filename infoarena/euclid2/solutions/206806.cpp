#include<iostream.h>   
#include<fstream.h>   
unsigned long x,a,b,i,d,divizor,ok;
int main ()   
{   
ifstream f("euclid2.in");   
ofstream g("euclid2.out");   
f>>x;   
for (i=0;i<x;i++)   
    {f>>a>>b;   
     d=2;divizor=1;   
	  while (d<=a && d<=b)
		  {ok=1;
			if (a%d==0 && b%d==0) {divizor*=d;a/=divizor;b/=divizor;ok=0;}
         if (ok==1) d++;}   
     g<<div<<'\n';   
    }   
return 0;   
}
