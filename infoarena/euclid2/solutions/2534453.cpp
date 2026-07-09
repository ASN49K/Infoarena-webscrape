#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    if(!b)    return a;
    return cmmdc(b,a%b);
}

int main()
{
    int a,b,n;
    in>>n;
    while (n--)
    {
    in>>a>>b;
    out<<cmmdc(a,b)<<'\n';
    }
    return 0;

}
