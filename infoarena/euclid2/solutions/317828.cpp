#include<fstream.h>
int main()
{ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int t,a,b,r,i;
f>>t;
for(i=1;i<=t;i++)
 {f>>a>>b;
  while(b!=0)
   {r=a%b;
    a=b;
    b=r;}
  g<<a<<"\n";
 }
return 0;
}