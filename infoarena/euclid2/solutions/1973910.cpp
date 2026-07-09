#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{int a,b,x;
f>>x;
for(int i=1;i<=x;++i){
f>>a>>b;
while(a!=b)if(a>b)a-=b; else b-=a;
g<<a<<endl;}
    return 0;
}
