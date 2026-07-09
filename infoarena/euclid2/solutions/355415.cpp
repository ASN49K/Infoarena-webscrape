#include<fstream.h>
long d,i,r,t;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main(){ in>>t;
while (t){t--;in>>d>>i;
r=d%i;
while(!r){d=i;i=r;r=d%i;}out<<i;}return 0;}