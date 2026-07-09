#include<iostream>
#include<fstream>
using namespace std;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");
int T;long a,b;
long cmmdc(long a, long b){
if ((a == b) && (a == 0))
return 1;
if (a * b == 0)
return a + b;
while (a != b)
if (a > b)
a -= b;
else
b -= a;
return a;
}
int main(){
fi>>T;
for(int i=1;i<=T;i++)
fi>>a>>b;
fo<<cmmdc(a,b)<<endl;

return 0;}
