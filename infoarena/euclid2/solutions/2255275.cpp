#include <iostream>

using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
int cmmdc(int a,int b)
{
    int rest;
    while(b)
    {
        rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}
int main()
{
    int a,b,T;
    f >> T;

    for (int i = 1;i <= T;i++)
    {
        f >> a >> b;
        g << cmmdc(a,b) << endl;
    }

    return 0;
}
