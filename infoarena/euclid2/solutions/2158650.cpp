# include <iostream>
# include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main(){

 int n,a,b,r;

 f>> n;

 for (int i = 0; i < n; i++){
  f>>a>>b;
  if (a > b){
   a = a+b;
   b = a-b;
   a = a-b;
  }

  while (b % a != 0){
   r = b % a;
   b = a;
   a = r;
  }
  g<<a<<'\n';
 }

 f.close();
 g.close();

 return 0;
}
