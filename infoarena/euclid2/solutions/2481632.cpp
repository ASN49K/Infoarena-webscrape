#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a, int b)
{
    int r=a%b;
    if(a%b==0)
    {
        return b;
    }
    else
    {
        return cmmdc(b, r);
    }
}
int main()
{

    int n, a, b;
    f>>n;
    while(n)
    {
        cin>>a>>b;
        g<<cmmdc(a, b)<<endl;
        t--;
    }

    return 0;
}
