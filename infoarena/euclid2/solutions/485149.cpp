#include<iostream.h>
#include<fstream.h>
main()
{ ifstream f("euclid2.in");
ofstream g("euclid2.out");

long a,b,t,i;

f>>t;

for(i=0;i<t;i++)
{ f>>a>>b;
  while(a!=b)
  {if(a>b) a=a-b;
   else b=b-a;
  }
  g<<a<<endl;
  
}
}