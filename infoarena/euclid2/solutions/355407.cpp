#include<fstream.h>
void main(){
long d,i,r,t;
ifstream in("euclid2.in");
ofstream out("adunare.in");
in>>t>>d>>i;
while (t){t--;
r=d%i;
while(!r){d=i;i=r;r=d%i;}out<<i;}}