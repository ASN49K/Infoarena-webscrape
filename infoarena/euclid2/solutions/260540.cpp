#include <fstream>

using namespace std;

fstream f;
fstream g;
long a;
long b;
int i;
int n;
long euclid(long a,long b)
{
   long r;
   r = a%b;
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
    f.open("euclid.in",fstream::in);
    g.open("euclid.out",fstream::out);
    f >> n;
    for(i=0;i<n;i++)
       {
                    f >> a >> b;
                    g << euclid(a,b) << "\n";
       }
    f.close();    
    g.close();   
    return 0;
}
