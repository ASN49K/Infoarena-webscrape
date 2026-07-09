#include <iostream>
#include <fstream>  
#include <math.h>  
using namespace std;
 ifstream f("euclid2.in");  
 ofstream g("euclid2.out"); 
long long t,a,b,n,i,r;
void ReadData()
{f>>n;
      for(i=1;i<=n;i++)
       { f>>a>>b; while(b!=0){r=a%b; a=b; b=r;  } g<<a<<endl;}
}   
 int main()
 {ReadData();
 f.close(); 
 g.close();
 return 0;} 
