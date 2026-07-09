#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a,int b){if(!b)return a;
return cmmdc(b,a%b);
}
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{int a,b,x;
f>>x;
for(int i=1;i<=x;++i){
f>>a>>b;
g<<cmmdc(a,b)<<endl;}
    return 0;
}
