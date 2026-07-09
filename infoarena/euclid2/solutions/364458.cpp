#include <fstream>

int gcd(long int a,long int b){
if(!b) return a;
else
return gcd(b,a%b);
}

int main(){
	long int a,b,t;
   ifstream fin("euclid2.in");
   ofstream fout("euclid2.out");

   fin>>t;

   for(;t>0;t--){
   	fin>>a>>b;
   	fout<<gcd(a,b)<<endl;
   }
}