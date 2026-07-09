#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");

int cmmdc(int a, int b)
{
    if(b==0)    return a;
    return cmmdc(b,a%b);
}

int main()
{
    int a,b,n;
    f>>n;
    while (n--)
    {
    f>>a>>b;
    o<<cmmdc(a,b)<<endl;
    }
    return 0;

}
