#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int Euclid(int x, int y)
{
    int tmp;
    while(x%y)
    {
        tmp=y;
        y=x%y;
        x=tmp;
    }
    return y;
}


int main()
{
    int T;
    in>>T;
    int x, y;
    while(T)
    {
        in>>x>>y;
        out<<Euclid(x,y)<<'\n';
        T--;
    }
    return 0;
}
