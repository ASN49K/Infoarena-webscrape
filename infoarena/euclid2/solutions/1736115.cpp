#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("euclid2.in");
ofstream out("euclid2.out");

int euclid(int x, int y)
{
    if(y==0)
        return x;
    else
        euclid(y,x%y);
}

int main()
{

    int T, a, b;
    in>>T;
    while(T)
    {
        in>>a>>b;
        out<<euclid(a,b)<<'\n';
        T--;
    }

    return 0;
}
