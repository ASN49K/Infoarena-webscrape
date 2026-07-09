#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a ,int  b)
{
    if(!b)
        return a;
    else
        return cmmdc(b , a%b);
}
int main()
{    int  t;
int a,b;

    f>>t;

    for( int i=0 ; i<t ; i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;

    }


}
