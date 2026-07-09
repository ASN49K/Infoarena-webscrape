#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int t;
    in>>t;
    int x,y;
    for(int i=1;i<=t;i++)
    {
        in>>x>>y;
        int r;
        while(y)
        {
            r = x%y;
            x = y;
            y = r;
        }
        out<<x<<'\n';
    }
    return 0;
}
