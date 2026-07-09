#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b)
{
    if(b==0)
        b=a;
    else
        return euclid(b,a%b);
}

int main()
{
    int n,x,y;
    in>>n;
    while(in>>x>>y)
    {
        out<<euclid(x,y)<<'\n';

    }

    in.close();
    out.close();
    return 0;
}
