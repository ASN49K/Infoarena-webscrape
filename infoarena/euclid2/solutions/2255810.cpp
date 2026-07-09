#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a,int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    int n;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        long long x,y;
        in>>x>>y;
        out<<euclid(x,y);
    }
    return 0;
}
