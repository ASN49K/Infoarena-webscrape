#include<fstream.h>
int a,b,nr;
int euclid(int a, int b){
 int t;
  while (b!=0) {
       t=b;
       b= a % b;
       a=t;
   }
   return a;
}
int main(){

   ifstream f("euclid2.in");
    f>>nr;
    ofstream g("euclid2.out");
    for( int i=0; i<nr;i++){
	  f>>a>>b;
	  g<<euclid(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
