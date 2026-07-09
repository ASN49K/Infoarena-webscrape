#include <iostream>
#include <fstream>
using namespace std;
int a,b;
int euclid(int x, int y){
while(x!=y){
if(x<y)y-=x;
else x-=y;
}
return euclid;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
int t;
f>>t;
    for(int i=t;i<=t;i++){
    f>>a>>b;
    g<<euclid(a,b)<<"\n";
    }
    return 0;
}
