#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,T;
int euclid(int a, int b)
{
    while(b)
    {
    int R=a%b;
        a=b;
        b=R;
    }
    return a;
}
int main()
{f>>T;
for(int i=1;i<=T;i++)
{
    f>>a>>b;
    g<<euclid(a,b)<<endl;
}
    return 0;
}
