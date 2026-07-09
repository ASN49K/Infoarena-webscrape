#include<iostream.h>
#include<fstream.h>

int main ()
{
    int a,b;
    
    fstream f("euclid2.in");
    ofstream g("euclid2.out");
    
    f>>a;
    f>>b;
    
    while (b!=a)
    {
          if (a>b)
          a=a-b;
         
         else       
          
          b=b-a;   
    }

   g<<a;

return 0;
}
