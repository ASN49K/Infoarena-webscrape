#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(long long a ,long long  b)
{
    if(!b)
        return a;
    else
        return cmmdc(b , a%b);
}
int main()
{   long int  t;
long long a,b;

    f>>t;

    for(long int i=0 ; i<t ; i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;

    }


}
