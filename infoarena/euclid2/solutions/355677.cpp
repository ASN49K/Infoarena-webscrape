#include<fstream.h>
long d,i,r,t,q;
void main(){ ifstream f;ofstream g;
f.open("euclid2.in");
g.open("euclid2.out");f>>t;
while(t){f>>d;f>>i;
r=d%i;
while(!r){d=i;i=r;r=d%i;}g<<i;}f.close();g.close();}