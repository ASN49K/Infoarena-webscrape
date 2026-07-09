#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int t,i,a,b,r;
    f>>t;
    for(i=1;i<=t;i++)
    {f>>a>>b;
      if(a>b)
      {
        while(b)
          {
	      r = a % b;
	      a = b;
	      b = r;
          }
        g<<a<<endl;
    }


  else  {


     while(a)
      {
	   r = b % a;
	   b = a;
	   b = r;
      }
     g<<b<<endl;
    }
    }


    return 0;
}
