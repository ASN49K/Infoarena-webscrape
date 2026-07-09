#include <iostream>
#include <fstream>
using namespace std;
int main()
{
ifstream A("euclid2.in");
ofstream B("euclid2.out");

    int a,b,r,T;
    A>>T;
    for(int i=1;i<=T;++i)
    {
        A>>a>>b;
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        B<<b<<endl;
    }
    A.close();
    B.close();
    return 0;
}
