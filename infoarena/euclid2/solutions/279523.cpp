#include<fstream>  
#include<iostream>  
   
std::ifstream fin("cmmdc.in");  
std::ofstream fout("cmmdc.out");  
   
int cmmdc(int a, int b)    
{    
    if (!b) return a;    
     return gcd(b, a % b);    
}    
   
int main(void)  
{  
     int a = -1,b = -1;  
     fin>>a>>b;  
     fout<<(gcd(a,b) == 1 ? 0 : cmmdc(a,b));
    return 0;  
}  
