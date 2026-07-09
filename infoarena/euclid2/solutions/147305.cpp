#include <fstream>  
#include <iostream>
using namespace std;
  
#define IN "euclid2.in"  
#define OUT "euclid2.out"  

ifstream fin(IN);
ofstream fout(OUT);

long a,b;

int main()    
{  
 fin>>a>>b;  
  fin.close();
  
 while(a*b)  
 {  
  if(a>b)  
   a%=b;  
  else  
   b%=a;  
 }  
  fout<<a+b<<"\n";  
   fout.close();  
   
return 0;  
}  
