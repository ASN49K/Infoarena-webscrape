#include<fstream.h>
#include<iostream.h>
#include<math.h>

int main()
{

unsigned long j,a,b,T,div,i,max;
ifstream f("euclid2.in");
f>>T;
ofstream g("euclid2.out");
for(i=1;i<=T;i++)
{f>>a>>b;
if(a<b)max=a;else max=b;
div=1;
for(j=1;j<=max;j++)
{
if(a%j==0 && b%j==0){div=div*j;
		     a=a/j;b=b/j;
		     }


}
g<<div<<endl;
}

g.close();
f.close();
return 0;
}