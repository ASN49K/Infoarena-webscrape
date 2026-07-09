#include<iostream.h>
#include<fstream.h>
main()
{ ifstream f("euclid2.in");
ofstream g("euclid2.out");

long a,b,t,i,c;

f>>t;

for(i=0;i<t;i++)
{ f>>a>>b;
  while(b)
  {c=a%b;
  a=b;
  b=c;
  }
  g<<a<<endl;
  
}
}
