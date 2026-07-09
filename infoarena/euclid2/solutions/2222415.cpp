#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int Alg(int x,int y)
{
    int t=0;
    while(x!=0)
    {
        t=x;
        x=y%x;
        y=t;
    }
    return t;
}

int main()
{int T,i=0,a,b;
f>>T;
while(i!=T)
{
    i++;
    f>>a>>b;
    g<<Alg(a,b)<<endl;

}

    return 0;
}
