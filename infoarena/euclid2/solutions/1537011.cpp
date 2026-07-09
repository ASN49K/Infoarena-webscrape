#include <iostream>
#include <fstream>

using namespace std;




int main()
{
long long t,a,b,i,c;
fstream f,g;
f.open("euclid2.in",ios::in);
g.open("euclid2.out",ios::out);
f>>t;
for(i=1;i<=t;i++){
f>>a>>b;
while(b!=0){
    c=b;
    b=a%b;
    a=c;}
g<<a<<'\n';
}
return 0;}
