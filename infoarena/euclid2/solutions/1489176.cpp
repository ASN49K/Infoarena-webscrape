#include <fstream>
#include <iostream>
using namespace std;

int euclid(int a,int b){
   if (!b) return a;
   return euclid(b,a%b);
}

int main(){
   ifstream fin("euclid.in");
   ofstream fout("euclid.out");

   int T;
   fin >> T;

   int a , b;
   while(T--){
      fin >> a >> b;
      fout << euclid(a,b) << "\n";
   }
   fin.close();
   fout.close();
   return 0;
}
