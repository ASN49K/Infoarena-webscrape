#include<fstream.h>
long d,i,r,t;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
void main(){in>>t;endl;
while (t){t--;in>>d>>i; endl;
r=d%i;
while(!r){d=i;i=r;r=d%i;}out<<i;}}