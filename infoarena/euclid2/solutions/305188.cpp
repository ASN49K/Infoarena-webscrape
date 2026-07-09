#include<fstream>
#include<iostream>
using namespace std;

int main()
{
    long t, a, b,i,r;
    
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
      f>>t;
      
    for(i=1;i<=t;i++)
     {
       f>>a>>b;
     while(b!=0)
       {
         r=a%b;
         a=b;
         b=r;
       }
    
      g<<a<<"\n";
     }
    f.close();
    g.close();
  return 0;
  
}
