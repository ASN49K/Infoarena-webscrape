#include<iostream>
#include<fstream>
int a,b,r,t;
int main()
{fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
f>>t;
for(;t>0;t--)
  {f>>a;f>>b;
  while(b!=0)
    {r=a%b;a=b;b=r;}
  g<<a<<endl;}

return 0;}