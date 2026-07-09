#include<fstream.h>
long d,i,r,t,q;
void main(){ifstream f;ofstream g;
f.open("euclid2.in");
g.open("euclid2.out");f>>t;cout<<endl;
while(t){t--;f>>d>>i;cout<<endl;
r=d%i;
while(r!=0){d=i;i=r;r=d%i;}g<<i<<endl;}f.close();g.close();}