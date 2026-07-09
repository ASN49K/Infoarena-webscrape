#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int T,a,b;

int euclid(int a,int b)
{
    if(b%a==0)
        return a;
    else
        return euclid(b%a,a);
}

int main()
{
    in>>T;
    while(T)
    {
        in>>a>>b;
        out<<euclid(a,b)<<'\n';
        T--;
    }
    return 0;
}
