#include<iostream.h>
#include<fstream.h>
int main()
{long a,b,i,t,x;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>t;
 for(i=1;i<=t;i++)
 {
  f>>a>>b;
  while(b!=0)
  {
   if(b==0)g<<a;
   else {  x=a;
	   a=b;
	   b=x%b;
         }

  }
  g<<a<<"\n";
 }
return 0;
}

