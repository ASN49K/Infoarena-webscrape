#include <iostream>
#include <fstream>
using namespace std;
int a,b;
int euclid(int x, int y){
while(x!=y){
if(x<y)y-=x;
else if (x>y) x-=y;
}
return x;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
int t;
f>>t;
    for(int i=1;i<=t;i++){
    f>>a;
    f>>b;
    g<<euclid(a,b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
