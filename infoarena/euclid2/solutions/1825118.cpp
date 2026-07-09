#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a,int b)
{
    if(b==0)
        return a;
    else
        return cmmdc(b,a%b);
}
int n,x,y;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>n;
    while(n--)
    {

        f>>x>>y;
        g<<cmmdc(x,y)<<endl;
    }

    return 0;
}
