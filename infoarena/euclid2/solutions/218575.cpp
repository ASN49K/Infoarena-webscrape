#include <fstream.h>
unsigned long a, b;int main(){
 {ifstream fin("cmmdc.in");fin>>a>>b;fin.close();}
 while(a&&b)if(a>b)a%=b;else b%=a;
 a+=b;if(a==1)a=0;
 {ofstream fout("cmmdc.out");fout<<a;fout.close();}
 return 0;}
 