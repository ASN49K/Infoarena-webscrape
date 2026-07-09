#include<fstream.h>
int main(){
long int T;
int a,b,i,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
g<<2*T<<'/n';
for(i=1;i<=T;i++){
f>>a>>b;
   while(b!=0){
   r=a%b;
   a=b;
   b=r;       }
g<<a<<'/n';      }
f.close();
g.close();
return 0;
}