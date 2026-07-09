#include <iostream>
#include <fstream>  
#include <math.h>  
using namespace std;
 ifstream f("euclid2.in");  
 ofstream g("euclid2.out"); 
long long t,a,b,n,i;
long long cmmdc( long long a, long long b)   
{   
         if( a%b == 0) return 0;   
         else  
             return cmmdc( b, a%b ); 
void ReadData()
{f>>n;
      for(i=1;i<=n;i++)
       { f>>a>>b; t=cmmdc(a,b); g<<t<<endl;}
}   
 int main()
 {ReadData();
 f.close(); 
 g.close();
 return 0;} 
