#include<iostream.h>
#include<fstream.h>
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
int main()
{
long a,b,r,t;
f>>t;
while(t!=0) {
f>>a>>b;
do {
r=a%b;
a=b;
b=r;
}
while(r!=0);
g<<a<<"\n";
t=t-1;}
f.close();
g.close();
return 0;
}