#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a, int b){
int r;
r=a%b;
while(r!=0){
a=b;
b=r;
r=a%b;}
return b;}
long x,y,i,t;
int main (){
f>>t;
for(i=1;i<=t;i++){
f>>x>>y;
g<<euclid(x,y)<<"\n";}
f.close();
g.close();
return 0;}