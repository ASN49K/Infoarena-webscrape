#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long a,b,r,cmmdc,t,i,x,y;
int main (){
f>>t;
for(i=1;i<=t;i++){
f>>x>>y;
a=x;
b=y;
r=a%b;
while(r!=0){
a=b;
b=r;
r=a%b;}
cmmdc=b;
g<<cmmdc;}
f.close();
g.close();
return 0;}