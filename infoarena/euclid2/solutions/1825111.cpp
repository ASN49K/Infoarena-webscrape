#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int cmmdc(int a,int b)
{
    if(b==0)
        return a;
    else
        return cmmdc(b,a%b);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n ;
    f>>n;
    while(n--)
    {
        int x,y;
        f>>x>>y;
        g<<cmmdc(x,y)<<endl;
    }

    return 0;
}
