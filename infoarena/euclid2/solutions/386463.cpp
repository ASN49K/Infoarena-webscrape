#include<fstream.h>
 ifstream f("cmmdc.in");
 ofstream g("cmmdc.out");
  int cmmdc(long long a,long long b){
  long r;
     while(b){
         r=a%b;
         a=b;
         b=r;
     }
     return a;
 }
  int main(){
      int n,i,a,b;
      f>>n;
      for(i=1;i<=n;i++){
          f>>a>>b;
          g<<cmmdc(a,b);
          g<<"\n";
      }
      g.close();
      return 0;
  }
