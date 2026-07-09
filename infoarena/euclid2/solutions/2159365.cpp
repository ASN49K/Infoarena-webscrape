# include <iostream>
# include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main(){

 int n,a,b;

 f>> n;

 for (int i = 0; i < n; i++){
  f>>a>>b;

  while (b % a != 0){
   b = (b % a) + a;
   a = b - a;
   b = b -a;
  }
  g<<a<<'\n';
 }

 f.close();
 g.close();

 return 0;
}
