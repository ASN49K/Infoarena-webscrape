#include <fstream.h>
unsigned long a, b;int main(){
 {ifstream fin("euclid2.in");fin>>a>>b;fin.close();}
 while(a&&b)if(a>b)a%=b;else b%=a;
 a+=b;{ofstream fout("euclid2.out");fout<<a;fout.close();}
 return 0;}
 