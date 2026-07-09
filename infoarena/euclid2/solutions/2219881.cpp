#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int x,int y)
{
    while(y>0)
    {
        int c=x%y;
        x=y;
        y=c;
    }
    return x;
}

int main()
{
    int t;
    in>>t;
    for(int i=1;i<=t;i++)
    {
        int x,y;
        in>>x>>y;
        out<<euclid(x,y)<<'\n';
    }
    return 0;
}
