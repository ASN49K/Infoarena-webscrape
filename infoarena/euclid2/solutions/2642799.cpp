#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
int a, b, d, T;
fin >> T;
for(int i = 0; i < T; i++){
fin >> a >> b;
while(a != b){
  if(a > b)
   a -= b;
  else
   b -= a;
}
d = a;
fout << d << endl;}
return 0;
}
