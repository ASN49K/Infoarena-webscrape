#include<fstream>
using namespace std;

int cmmdc(int a, int b)
{
    int r;
  if(a==b)
     return a;
 
  while(b)
    {
      r=a%b;
      a=b;
      b=r;
    }
  return a;
}
  
int main()
{    
   long t, a, b, i;
     ofstream g("euclid2.out");
     ifstream f("euclid2.in");
        f>>t;
        
     for(i=1;i<=t;i++)
       {
         f>>a>>b;
         g<<cmmdc(a,b)<<"\n";
       }
      f.close();
      g.close(); 
    return 0;
}
