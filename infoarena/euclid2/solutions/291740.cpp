#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(long a, long b){

   while(a!=b)
     if(a>b)a=a-b;
     else b=b-a;
   return a;
}
int main (){
  long n,a,b;
  f>>n;
  for(long i=0; i<n; i++){
     f>>a>>b;
     g<<euclid(a,b)<<'\n'; }
  f.close();
  g.close();
  return 0;
  }