#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
    int r;
    r=a%b;
    if(r)
        return cmmdc(b,r);
    else
        return b;
}
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
int main()
{
    int t; f>>t;
    int a,b;
    for(t;!t;t--){
    f>>a>>b;
    g<<cmmdc(a,b);
    g<<endl;
}
    return 0;
}
