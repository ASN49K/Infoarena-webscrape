#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b){
   return (b ? gcd(b, a%b) : a);
}

int main(){
   int tt, a, b;
   fin >> tt;
   while(tt--){
      fin >> a >> b;
      fout << gcd(a, b) << '\n';
   }
   return 0;
}