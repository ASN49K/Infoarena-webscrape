#include <iostream.h>
#include <fstream.h>
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
int main()
{
 long int a,b;
 int n,i;
 f>>n;
 for (i=0;i<n;++i)
     {
      f>>a>>b;
      while (a!=b)
       {
        if (a>b) a=a-b;
           else b=b-a; 
            
       } 
      g<<a<<endl;            
     }
 return 0;   
}
