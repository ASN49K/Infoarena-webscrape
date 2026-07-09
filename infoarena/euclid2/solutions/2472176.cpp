#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a , int b)
{
    if(b>a)
        swap(a,b);
    while(b!=0)
    {
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t , a , b ;
    f >> t ;
    while(t>0)
    {
        f >> a >> b ;
        g << cmmdc(a,b) << '\n';
        t--;
    }
    return 0;
}
