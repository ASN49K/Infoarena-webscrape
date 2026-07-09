#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");

long euclid2(long a,long b)
{
while(a!=b)
if(a>b)
 a=a-b;
 else
 b=b-a;

return a;
}

int main()
{
long t,a,b,i;
f>>t;
for(i=1;i<=t;i++)
 {
 f>>a;
 f>>b;
 g<<euclid2(a,b)<<"\n";
 }

}

