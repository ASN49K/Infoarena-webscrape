#include<fstream.h>
long d,i,r,t,q;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
void main(){in>>t;
for(q=1;q<=t;q++){in>>d>>i;
r=d%i;
while(!r){d=i;i=r;r=d%i;}out<<i;}}