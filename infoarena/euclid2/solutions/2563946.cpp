#include <iostream>
#include <fstream>

using namespace std;
int euclid(int x,int y){
    if(!y) return x;
    return euclid(y, x%y);
}
int a,b,n;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    while(n--){
        f>>a>>b;
        g<<euclid(a,b)<<endl;
}
    return 0;
}
