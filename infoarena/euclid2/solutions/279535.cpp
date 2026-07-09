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
     int a = -1,b = -1;  
     fin>>a>>b;  
     fout<<cmmdc(a,b);
    return 0;  
}  
