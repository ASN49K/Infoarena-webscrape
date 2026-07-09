#include<fstream.h>
 int cmmdc(int a, int b){
  int aux,i;
   if(a<b){
    aux=a;
    a=b;
    b=aux;
   }
   while(b!=0){
    aux=b;
    b=a%b;
    a=aux;
   }
  return a;
 }
int main(){
int n,i,a,b;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>n;
 for(i=0;i<n*2;i++){
  if(i%2==1){
   f>>b;
   g<<cmmdc(a,b)<<"\n";
  }
  else
   f>>a;
  }
 f.close();
 g.close();
 return 0;
 }