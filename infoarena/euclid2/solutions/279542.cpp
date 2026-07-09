#include<fstream>  
#include<iostream>  
   
std::ifstream fin("euclid2.in");  
std::ofstream fout("euclid2.out");  
   
int cmmdc(int a, int b)    
{    
    if (!b) return a;    
     return cmmdc(b, a % b);    
}    
   
int main(void)  
{  
     int n,a,b; 
     fin>>n; 
     for(int i = 1; i <= n; i++) 
      { fin>>a>>b;
       fout<<cmmdc(a,b)<<"\n";
      }
    return 0;  
}  
