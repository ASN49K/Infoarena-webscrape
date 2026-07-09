#include <iostream>   
#include <fstream>     
#include <math.h>     
  
using namespace std;   
  
int main()   
{   
     ifstream f("euclid2.in");     
     ofstream g("euclid2.out");    
    long x;   
    f>>x;   
    long a,b,r;   
    while(x!=0)   
        {   
            f>>a>>b;   
            while(b!=0){r=a%b;a=b;b=r;}   
            g<<a<<'\n';   
            x--;   
        }   
    g.close();   
    return 0;   
}  
