#include <fstream>

using namespace std;

fstream f,g;
long a,b,n;

// Greatest Common Divisor - Euclid's Algorithm ( Division method )
long euclid(long a,long b)
{
   long r= a%b;
   while(r)             
   {
      a=b;
      b=r;
      r=a%b;        
   }
        return b;
}

int main()
{
    f.open("euclid2.in",fstream::in);
    f >> n;
    g.open("euclid2.out",fstream::out);
    for(int i=0;i<n;i++)
     {
            f >> a >> b;
            g << euclid(a,b)<<"\n";
            }
    g.close();
    f.close();    
    return 0;
    
}
