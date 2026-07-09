#include <iostream>
#include <fstream>
using namespace std;
int euclid(int x,int y){
    if(y==0) return x;
    x%=y;
    return euclid(y, x);
}
int a,b,n;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    while(n--){
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }
}
